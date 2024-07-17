
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <filename>\
", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    FILE *fp;
    char url[256];

    curl = curl_easy_init();
    if (curl) {
        snprintf(url, sizeof(url), "ftp://%s/%s", argv[1], argv[4]);
        fp = fopen(argv[4], "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_USERNAME, argv[2]);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, argv[3]);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\
", curl_easy_strerror(res));
        } else {
            printf("File downloaded successfully.\
");
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return 0;
}
