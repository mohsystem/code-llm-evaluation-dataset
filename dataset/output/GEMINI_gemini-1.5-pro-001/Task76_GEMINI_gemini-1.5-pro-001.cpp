#include <iostream>
#include <string>
#include <curl/curl.h>
#include <regex>

using namespace std;

// Callback function for cURL to write data to a stringstream
size_t write_callback(void *contents, size_t size, size_t nmemb, string *s) {
    size_t newLength = size * nmemb;
    size_t oldLength = s->size();
    try {
        s->resize(oldLength + newLength);
    } catch (const std::bad_alloc &e) {
        cerr << "Error allocating memory: " << e.what() << endl;
        return 0; // Indicate failure to cURL
    }
    copy((char*) contents, (char*) contents + newLength, s->begin() + oldLength);
    return size * nmemb;
}

string extractTitle(const string &html) {
    regex titleRegex("<title>(.*?)</title>", regex_constants::icase);
    smatch match;
    if (regex_search(html, match, titleRegex)) {
        return match[1].str();
    } else {
        return "";
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <url>" << endl;
        return 1;
    }

    string url = argv[1];

    CURL *curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return 1;
        }

        string title = extractTitle(response);
        cout << title << endl;
    }

    return 0;
}