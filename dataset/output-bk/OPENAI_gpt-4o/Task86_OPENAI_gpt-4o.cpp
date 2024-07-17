#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <cstdlib>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    std::ofstream* out = (std::ofstream*)userp;
    out->write((char*)contents, size * nmemb);
    return size * nmemb;
}

void downloadFile(const std::string& url, const std::string& fileName) {
    CURL* curl;
    CURLcode res;
    std::ofstream file(fileName, std::ios::binary);
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: <application> <URL>" << std::endl;
        return 1;
    }
    downloadFile(argv[1], "downloaded_program.exe");
    system("downloaded_program.exe");
    return 0;
}