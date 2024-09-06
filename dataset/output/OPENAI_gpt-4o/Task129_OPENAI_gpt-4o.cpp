#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    }
    catch (std::bad_alloc& e) {
        return 0;
    }
    return newLength;
}

std::string fetchFile(const std::string& fileName) {
    CURL* curl;
    CURLcode res;
    std::string url = "http://example.com/" + fileName;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            return "Failed to retrieve file: " + std::string(curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return readBuffer;
}

int main() {
    std::string fileName;
    std::cout << "Enter file name: ";
    std::cin >> fileName;
    std::string fileContent = fetchFile(fileName);
    std::cout << fileContent << std::endl;
    return 0;
}