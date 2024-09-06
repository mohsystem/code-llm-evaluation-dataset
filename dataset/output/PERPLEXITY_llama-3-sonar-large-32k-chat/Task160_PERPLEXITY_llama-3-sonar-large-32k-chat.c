// This code uses the curl library, which is not a standard C library.
// You need to install libcurl and link against it to compile this code.

#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    strcat((char*)userp, (char*)contents);
    return size * nmemb;
}

int main() {
    char url[256];
    printf("Enter a URL: ");
    fgets(url, 256, stdin);
    url[strcspn(url, "\n")] = 0; // remove newline character

    CURL *curl;
    CURLcode res;
    char readBuffer[10240];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuffer);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
        } else {
            printf("Status Code %ld\n", curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE));
            printf("Headers: %s\n", curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL));
            printf("Content: %s\n", readBuffer);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}