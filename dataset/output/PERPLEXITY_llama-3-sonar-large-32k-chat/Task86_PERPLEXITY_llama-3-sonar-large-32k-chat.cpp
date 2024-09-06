#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    std::ostream &os = *static_cast<std::ostream*>(stream);
    os.write(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

int main() {
    std::string url;
    std::cout << "Enter the URL of the EXE file: ";
    std::cin >> url;
    std::string filename = url.substr(url.find_last_of('/') + 1);
    std::ofstream file(filename, std::ios::binary);
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    std::system(filename.c_str());
    return 0;
}