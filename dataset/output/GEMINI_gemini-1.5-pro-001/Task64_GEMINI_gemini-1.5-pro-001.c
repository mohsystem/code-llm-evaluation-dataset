#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
// You need to include a JSON parsing library for C
// Example using the "cJSON" library:
#include "cJSON.h" 

// Callback function for cURL to write data to a string
size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    char** buffer = (char**)userp;
    *buffer = (char*)realloc(*buffer, strlen(*buffer) + totalSize + 1);
    if (*buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }
    memcpy(*buffer + strlen(*buffer), contents, totalSize);
    (*buffer)[strlen(*buffer) + totalSize] = '\0';
    return totalSize;
}

// Function to fetch JSON from a URL
cJSON* getJsonFromUrl(const char* url) {
    CURL* curl = curl_easy_init();
    char* responseBuffer = NULL;
    cJSON* json = NULL;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            json = cJSON_Parse(responseBuffer);
            if (json == NULL) {
                const char* errorPtr = cJSON_GetErrorPtr();
                if (errorPtr != NULL) {
                    fprintf(stderr, "JSON parsing error before: [%s]\n", errorPtr);
                }
            }
        } else {
            fprintf(stderr, "Error fetching URL: %s\n", curl_easy_strerror(res));
        }
        free(responseBuffer);
        return json;
    } else {
        fprintf(stderr, "Error initializing cURL\n");
        return NULL;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    const char* url = argv[1];
    cJSON* jsonData = getJsonFromUrl(url);

    if (jsonData != NULL) {
        char* jsonString = cJSON_Print(jsonData);
        printf("%s\n", jsonString);
        cJSON_Delete(jsonData);
        free(jsonString);
    }

    return 0;
}