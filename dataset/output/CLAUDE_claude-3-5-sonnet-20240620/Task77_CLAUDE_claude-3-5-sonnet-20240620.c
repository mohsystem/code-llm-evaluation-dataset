
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <hostname> <username> <password> <filename>\\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *filename = argv[4];

    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename, "wb");
        char url[256];
        snprintf(url, sizeof(url), "ftp://%s/%s", hostname, filename);
        
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        
        curl_easy_cleanup(curl);
        fclose(fp);

        if (res == CURLE_OK) {
            printf("File %s downloaded successfully.\\n", filename);
        } else {
            printf("Failed to download the file: %s\\n", curl_easy_strerror(res));
        }
    }

    return 0;
}
