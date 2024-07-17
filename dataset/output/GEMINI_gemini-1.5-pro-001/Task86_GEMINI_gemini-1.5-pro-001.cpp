#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#endif

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Please provide a URL as an argument." << endl;
        return 1;
    }

    CURL *curl;
    FILE *fp;
    CURLcode res;
    string url = argv[1];
    string filename = "downloaded.exe";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename.c_str(), "wb");
        if (fp == NULL) {
            cerr << "Error opening file for writing" << endl;
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        fclose(fp);

        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return 1;
        }
    }

    curl_global_cleanup();

    // Execute the downloaded file
    #ifdef _WIN32
    WinExec(filename.c_str(), SW_SHOW);
    #else
    execl(filename.c_str(), filename.c_str(), NULL);
    #endif

    return 0;
}