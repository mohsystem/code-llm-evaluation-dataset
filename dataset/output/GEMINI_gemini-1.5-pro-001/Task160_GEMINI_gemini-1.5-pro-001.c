#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function for cURL to write data to a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, char** output) {
    size_t totalSize = size * nmemb;
    *output = (char*)realloc(*output, totalSize + 1);
    if (*output == NULL) {
        fprintf(stderr, "Out of memory!\n");
        return 0;
    }
    memcpy(*output, contents, totalSize);
    (*output)[totalSize] = '\0';
    return totalSize;
}

int main() {
    char url[1024];
    printf("Enter URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0; // Remove trailing newline

    CURL* curl = curl_easy_init();
    if (curl) {
        char* response = NULL;
        size_t responseSize = 0;

        // Set URL and other options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response);
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(response);
    }

    return 0;
}