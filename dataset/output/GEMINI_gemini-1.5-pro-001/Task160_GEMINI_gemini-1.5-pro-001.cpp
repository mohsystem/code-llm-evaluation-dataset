#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function for cURL to write data
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    string url;

    cout << "Enter a URL: ";
    getline(cin, url);

    CURL* curl = curl_easy_init();
    if (curl) {
        string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            cout << response << endl;
        } else {
            cerr << "Error: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    } else {
        cerr << "Error initializing cURL." << endl;
    }

    return 0;
}