#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Callback function for cURL to write data
size_t writeCallback(void* contents, size_t size, size_t nmemb, char** output) {
    size_t totalSize = size * nmemb;
    *output = (char*)realloc(*output, strlen(*output) + totalSize + 1);
    if (*output == NULL) {
        fprintf(stderr, "Memory allocation failed.
");
        return 0;
    }
    memcpy(*output + strlen(*output), contents, totalSize);
    (*output)[strlen(*output) + totalSize] = '\0';
    return totalSize;
}

int main() {
    char url[1024];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);

    // Remove trailing newline from fgets input
    if (url[strlen(url) - 1] == '
') {
        url[strlen(url) - 1] = '\0';
    }

    CURL* curl = curl_easy_init();
    if (curl) {
        char* response = (char*)malloc(1);
        response[0] = '\0';

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            printf("%s
", response);
        } else {
            fprintf(stderr, "Error: %s
", curl_easy_strerror(res));
        }

        free(response);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Error initializing cURL.
");
    }

    return 0;
}