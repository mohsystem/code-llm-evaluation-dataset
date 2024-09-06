
#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void download_file(const std::string& url, const std::string& filename) {
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

int main() {
    std::string url;
    std::cout << "Enter the URL of the EXE file: ";
    std::cin >> url;

    size_t pos = url.find_last_of("/");
    std::string filename = url.substr(pos + 1);

    download_file(url, filename);

    #ifdef _WIN32
        system(filename.c_str());
    #else
        system(("chmod +x " + filename).c_str());
        system(("./" + filename).c_str());
    #endif

    return 0;
}
