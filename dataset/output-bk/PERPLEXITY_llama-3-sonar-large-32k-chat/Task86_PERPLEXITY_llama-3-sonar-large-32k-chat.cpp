#include <iostream>
#include <string>
#include <curl/curl.h>
#include <windows.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    FILE *fp = (FILE *)userp;
    fwrite(contents, size, nmemb, fp);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    std::string url = "http://example.com/program.exe";
    std::string fileName = "program.exe";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(fileName.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();

    ShellExecute(NULL, "open", fileName.c_str(), NULL, NULL, SW_SHOW);
    return 0;
}