
#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " <hostname> <username> <password> <filename>" << std::endl;
        return 1;
    }

    std::string hostname = argv[1];
    std::string username = argv[2];
    std::string password = argv[3];
    std::string filename = argv[4];

    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename.c_str(), "wb");
        std::string url = "ftp://" + hostname + "/" + filename;
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERNAME, username.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        
        curl_easy_cleanup(curl);
        fclose(fp);

        if (res == CURLE_OK) {
            std::cout << "File " << filename << " downloaded successfully." << std::endl;
        } else {
            std::cout << "Failed to download the file: " << curl_easy_strerror(res) << std::endl;
        }
    }

    return 0;
}
