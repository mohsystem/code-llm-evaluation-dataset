#include <iostream>
#include <string>
#include <curl/curl.h>

// Callback function for cURL to write data to a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    std::string url;
    std::cout << "Enter URL: ";
    std::getline(std::cin, url);

    CURL* curl = curl_easy_init();
    if (curl) {
        std::string response;

        // Set URL and other options
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Response:\n" << response << std::endl;
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    return 0;
}