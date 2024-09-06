#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp> // You likely need to install a JSON library

// Callback function for cURL to write data to a string
size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    ((std::string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}

// Function to fetch JSON from a URL
nlohmann::json getJsonFromUrl(const std::string& url) {
    CURL* curl = curl_easy_init();
    std::string responseBuffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            try {
                return nlohmann::json::parse(responseBuffer);
            } catch (nlohmann::json::parse_error& e) {
                std::cerr << "JSON parsing error: " << e.what() << std::endl;
                return nlohmann::json();
            }
        } else {
            std::cerr << "Error fetching URL: " << curl_easy_strerror(res) << std::endl;
            return nlohmann::json();
        }
    } else {
        std::cerr << "Error initializing cURL" << std::endl;
        return nlohmann::json();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <url>" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    nlohmann::json jsonData = getJsonFromUrl(url);

    if (!jsonData.empty()) {
        std::cout << jsonData.dump(4) << std::endl; // Pretty-print JSON
    }

    return 0;
}