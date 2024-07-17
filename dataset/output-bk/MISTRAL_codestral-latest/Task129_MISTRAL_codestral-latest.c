#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmeb, stream);
    return written;
}

int main() {
    char fileName[256];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    char url[512] = "http://example.com/";
    strcat(url, fileName);

    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(fileName, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}