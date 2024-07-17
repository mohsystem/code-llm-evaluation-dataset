#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmeb, stream);
    return written;
}

int main() {
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::string url = "http://example.com/" + fileName;

    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(fileName.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}