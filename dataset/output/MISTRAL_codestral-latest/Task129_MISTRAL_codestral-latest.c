// C
/*
 * This code requires libcurl library to be installed.
 * Compile with: gcc -o download_file download_file.c -lcurl
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *file = (FILE *)userp;
    if (file != NULL) {
        fwrite(contents, size, nmemb, file);
        return realsize;
    }
    return 0;
}

int main() {
    char fileName[256];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    char url[512];
    sprintf(url, "http://example.com/%s", fileName);

    CURL *curl;
    FILE *fp;
    CURLcode res;

    fp = fopen(fileName, "wb");
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    fclose(fp);

    return 0;
}