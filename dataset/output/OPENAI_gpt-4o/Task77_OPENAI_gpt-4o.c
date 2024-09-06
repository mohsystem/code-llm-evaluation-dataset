#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *filename = argv[4];

    CURL *curl;
    FILE *fp;
    CURLcode res;
    char ftp_url[256];

    snprintf(ftp_url, sizeof(ftp_url), "ftp://%s/%s", hostname, filename);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, ftp_url);
        curl_easy_setopt(curl, CURLOPT_USERPWD, strcat(strcat(username, ":"), password));
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();
    return 0;
}