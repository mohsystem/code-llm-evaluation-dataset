#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to write data to a file
size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int download_file(const char* url, const char* filename) {
    CURL* curl;
    FILE* fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename, "wb");
        if (!fp) {
            fprintf(stderr, "Error opening file for writing: %s\n", filename);
            curl_easy_cleanup(curl);
            return 1; // Indicate failure
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            fclose(fp);
            curl_easy_cleanup(curl);
            return 1; // Indicate failure
        }

        fclose(fp);
        curl_easy_cleanup(curl);
        return 0; // Indicate success
    } else {
        fprintf(stderr, "curl_easy_init() failed.\n");
        return 1; // Indicate failure
    }
}

int main() {
    char filename[256];
    printf("Enter the file name to download: ");
    scanf("%s", filename);

    char url[512];
    snprintf(url, sizeof(url), "https://example.com/files/%s", filename); // Replace with actual server URL

    if (download_file(url, filename) == 0) {
        printf("File '%s' downloaded successfully.\n", filename);
    } else {
        fprintf(stderr, "Error downloading file.\n");
    }

    return 0;
}