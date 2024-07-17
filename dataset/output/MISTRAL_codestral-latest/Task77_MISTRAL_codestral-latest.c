#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <hostname> <username> <password> <file>
", argv[0]);
        return 1;
    }

    CURL *curl;
    FILE *fp;
    char *url;
    char *filename = argv[4];

    url = malloc(strlen(argv[1]) + strlen(argv[3]) + strlen(argv[4]) + 10);
    sprintf(url, "ftp://%s:%s@%s/%s", argv[2], argv[3], argv[1], argv[4]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen(filename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    free(url);

    return 0;
}