// CPP
#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    std::ofstream *file = (std::ofstream *)userp;
    if (file != NULL) {
        file->write((char*)contents, realsize);
        return realsize;
    }
    return 0;
}

int main() {
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;
    std::string url = "http://example.com/" + fileName;

    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *urlStr = new char[url.length() + 1];
    strcpy(urlStr, url.c_str());

    std::ofstream outFile(fileName, std::ios::binary);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, urlStr);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outFile);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    outFile.close();
    delete[] urlStr;

    return 0;
}