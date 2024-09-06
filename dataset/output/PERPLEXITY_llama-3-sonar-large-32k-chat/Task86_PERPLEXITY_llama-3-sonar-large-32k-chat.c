#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    fwrite(ptr, size, nmemb, (FILE*)stream);
    return size * nmemb;
}

int main() {
    char url[256];
    printf("Enter the URL of the EXE file: ");
    scanf("%255s", url);
    char *filename = strrchr(url, '/');
    filename = filename ? filename + 1 : url;
    FILE *file = fopen(filename, "wb");
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    system(filename);
    return 0;
}