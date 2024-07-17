#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    FILE* fp = (FILE*)userp;
    size_t totalSize = size * nmemb;
    fwrite(contents, size, nmemb, fp);
    return totalSize;
}

int main() {
    char filename[256];
    printf("Enter the filename to retrieve: ");
    scanf("%s", filename);

    char url[512];
    snprintf(url, sizeof(url), "http://example.com/%s", filename);

    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        FILE* fp = fopen(filename, "wb");
        if (!fp) {
            perror("Cannot open file for writing");
            exit(EXIT_FAILURE);
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s
", curl_easy_strerror(res));
        } else {
            printf("File '%s' has been retrieved successfully.
", filename);
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    curl_global_cleanup();
    return 0;
}