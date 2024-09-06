#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[]) {
    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *filename = argv[4];
    
    CURL *curl;
    CURLcode res;
    FILE *fp;

    std::string ftp_url = "ftp://" + std::string(hostname) + "/" + std::string(filename);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(filename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, ftp_url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERPWD, (std::string(username) + ":" + std::string(password)).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();
    return 0;
}