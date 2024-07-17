#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[size * nmemb] = 0;
    strcat((char*)userp, contents);
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>
", argv[0]);
        return 1;
    }
    CURL *curl;
    CURLcode res;
    char url[1024];
    strcpy(url, argv[1]);
    char readBuffer[10240];
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s
", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    json_object *jobj = json_tokener_parse(readBuffer);
    printf("%s
", json_object_to_json_string(jobj));
    json_object_put(jobj);
    curl_global_cleanup();
    return 0;
}