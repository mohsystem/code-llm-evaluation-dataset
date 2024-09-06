
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_URL_LENGTH 512

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void retrieve_file(const char* filename) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char url[MAX_URL_LENGTH];
    const char* server_url = "http://example.com/files/";  // Replace with actual server URL

    snprintf(url, sizeof(url), "%s%s", server_url, filename);

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Error: Unable to open file for writing.\\n");
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error retrieving file: %s\\n", curl_easy_strerror(res));
        } else {
            printf("File '%s' successfully retrieved and saved.\\n", filename);
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Error: Unable to initialize CURL.\\n");
    }
}

int main() {
    char user_filename[MAX_FILENAME_LENGTH];

    printf("Enter the filename to retrieve: ");
    if (fgets(user_filename, sizeof(user_filename), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(user_filename);
        if (len > 0 && user_filename[len-1] == '\\n') {
            user_filename[len-1] = '\\0';
        }

        retrieve_file(user_filename);
    } else {
        fprintf(stderr, "Error reading input.\\n");
    }

    return 0;
}
