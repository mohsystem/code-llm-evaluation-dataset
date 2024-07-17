
#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string extractTitle(const std::string& html) {
    std::regex titleRegex("<title>(.*?)</title>");
    std::smatch match;

    if (std::regex_search(html, match, titleRegex) && match.size() > 1) {
        return match.str(1);
    }

    return "Title not found";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <URL>" << std::endl;
        return 1;
    }

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::string title = extractTitle(readBuffer);
            std::cout << "Page Title: " << title << std::endl;
        }
    }

    return 0;
}
