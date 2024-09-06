// Note: This code uses the libcurl and json-c libraries, which need to be installed and linked.
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    strcat((char*)userp, (char*)contents);
    return size * nmemb;
}

struct json_object *readJsonFromUrl(char *url) {
    CURL *curl;
    CURLcode res;
    char readBuffer[1024] = "";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "cURL error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    struct json_object *json = json_tokener_parse(readBuffer);
    if (!json) {
        fprintf(stderr, "JSON parse error\n");
    }
    return json;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    struct json_object *json = readJsonFromUrl(url);
    json_object_put(json);
    return 0;
}