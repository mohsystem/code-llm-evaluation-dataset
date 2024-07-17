#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    std::string *str = (std::string *)userp;
    str->append((char *)contents, realsize);
    return realsize;
}

int main() {
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);

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

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s
", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        std::cout << readBuffer << std::endl;
    }

    curl_global_cleanup();
    return 0;
}