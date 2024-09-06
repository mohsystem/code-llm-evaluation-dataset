// This code uses the curl library, which is not a standard C++ library.
// You need to install libcurl and link against it to compile this code.

#include <curl/curl.h>
#include <iostream>
#include <string>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    std::string url;
    std::cout << "Enter a URL: ";
    std::cin >> url;

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Status Code: " << curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE) << std::endl;
            std::cout << "Headers: " << curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL) << std::endl;
            std::cout << "Content: " << readBuffer << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}