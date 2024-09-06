
#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string getPageTitle(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            return "Error: " + std::string(curl_easy_strerror(res));
        }
    }

    std::regex titleRegex("<title>(.*?)</title>");
    std::smatch match;
    if (std::regex_search(readBuffer, match, titleRegex) && match.size() > 1) {
        return match.str(1);
    }

    return "No title found";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <url>" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    std::string title = getPageTitle(url);
    std::cout << "Page title: " << title << std::endl;

    return 0;
}
