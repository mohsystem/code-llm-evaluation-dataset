/* C code to make an HTTP request to a URL */
#include <stdio.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    printf("%s", (char *)contents);
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;
    char url[100];

    printf("Enter a URL: ");
    fgets(url, 100, stdin);
    url[strcspn(url, "\n")] = 0; // remove trailing newline

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}