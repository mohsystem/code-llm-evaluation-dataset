#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function to write data to a file
size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

bool download_file(const string& url, const string& filename) {
    CURL* curl;
    FILE* fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename.c_str(), "wb");
        if (!fp) {
            cerr << "Error opening file for writing: " << filename << endl;
            curl_easy_cleanup(curl);
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            fclose(fp);
            curl_easy_cleanup(curl);
            return false;
        }

        fclose(fp);
        curl_easy_cleanup(curl);
        return true;
    } else {
        cerr << "curl_easy_init() failed." << endl;
        return false;
    }
}

int main() {
    string filename;
    cout << "Enter the file name to download: ";
    cin >> filename;

    string url = "https://example.com/files/" + filename; // Replace with actual server URL

    if (download_file(url, filename)) {
        cout << "File '" << filename << "' downloaded successfully." << endl;
    } else {
        cerr << "Error downloading file." << endl;
    }

    return 0;
}