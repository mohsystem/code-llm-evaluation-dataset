#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp) == NULL ? strncpy(((char*)userp), (char*)contents, size * nmemb) : strcat(((char*)userp), (char*)contents);
    return size * nmemb;
}

int main() {
    char url[256];
    char buffer[10000] = {0};

    printf("Enter a URL: ");
    scanf("%255s", url);

    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    printf("%s\n", buffer);
    return 0;
}