#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Callback function for cURL to write data to a string
size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t realsize = size * nmemb;
    output->append((char*)contents, realsize);
    return realsize;
}

// Function to fetch JSON data from a URL
json fetch_json_from_url(const std::string& url) {
    CURL* curl = curl_easy_init();
    json json_data;

    if (curl) {
        std::string response_data;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            json_data = json::parse(response_data);
        }
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Failed to initialize libcurl" << std::endl;
    }

    return json_data;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <url>" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    json data = fetch_json_from_url(url);

    if (!data.empty()) {
        std::cout << data.dump(4) << std::endl; // Pretty print with 4 spaces indentation
    }

    return 0;
}