
#include <iostream>
#include <string>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <hostname> <username> <password> <filename>" << std::endl;
        return 1;
    }

    CURL *curl;
    CURLcode res;
    FILE *fp;
    std::string url = "ftp://" + std::string(argv[1]) + "/" + std::string(argv[4]);

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(argv[4], "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_USERNAME, argv[2]);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, argv[3]);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "File downloaded successfully." << std::endl;
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return 0;
}
