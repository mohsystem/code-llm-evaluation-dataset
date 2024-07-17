#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to write downloaded data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    char fileName[256];
    printf("Enter the file name to download: ");
    scanf("%s", fileName);

    char baseUrl[] = "https://example.com/files/"; // Replace with your base URL
    char fileUrl[512];
    snprintf(fileUrl, sizeof(fileUrl), "%s%s", baseUrl, fileName);

    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(fileName, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file for writing.
");
            curl_easy_cleanup(curl);
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, fileUrl);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s
",
                    curl_easy_strerror(res));
        } else {
            printf("File '%s' downloaded successfully!
", fileName);
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    return 0;
}