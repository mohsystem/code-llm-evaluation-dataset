#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    strcat((char*)userp, (char*)contents);
    return size * nmemb;
}

int main() {
    char url[256];
    printf("Enter a URL: ");
    fgets(url, 256, stdin);
    url[strcspn(url, "
")] = 0; // remove newline character

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
            fprintf(stderr, "cURL error: %s
", curl_easy_strerror(res));
        } else {
            printf("Response Content: %s
", readBuffer);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}