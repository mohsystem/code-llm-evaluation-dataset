#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function to write downloaded data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    string fileName;
    cout << "Enter the file name to download: ";
    cin >> fileName;
    string baseUrl = "https://example.com/files/"; // Replace with your base URL
    string fileUrl = baseUrl + fileName;

    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(fileName.c_str(), "wb");
        if (fp == nullptr) {
            cerr << "Error opening file for writing." << endl;
            curl_easy_cleanup(curl);
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, fileUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        } else {
            cout << "File '" << fileName << "' downloaded successfully!" << endl;
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    return 0;
}