#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmeb, stream);
    return written;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        std::cout << "Usage: " << argv[0] << " <hostname> <username> <password> <file>
";
        return 1;
    }

    CURL *curl;
    FILE *fp;
    std::string url = "ftp://" + std::string(argv[2]) + ":" + std::string(argv[3]) + "@" + std::string(argv[1]) + "/" + std::string(argv[4]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(argv[4], "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return 0;
}