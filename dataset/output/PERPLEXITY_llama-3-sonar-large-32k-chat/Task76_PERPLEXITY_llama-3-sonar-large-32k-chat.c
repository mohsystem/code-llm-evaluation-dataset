#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

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
        } else {
            regex_t regex;
            regcomp(&regex, "<title>(.*?)</title>", REG_EXTENDED);
            regmatch_t pm;
            if (!regexec(&regex, readBuffer, 1, &pm, 0)) {
                char title[1024];
                strncpy(title, readBuffer + pm.rm_so, pm.rm_eo - pm.rm_so);
                title[pm.rm_eo - pm.rm_so] = 0;
                printf("%s
", title);
            } else {
                printf("No title found
");
            }
            regfree(&regex);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}