#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <curl/curl.h>

struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len +1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed
");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed
");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr + s->len, ptr, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        CURL *curl;
        CURLcode res;
        struct string s;
        init_string(&s);

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if(res == CURLE_OK) {
                regex_t regex;
                regmatch_t pmatch[2];
                regcomp(&regex, "<title>(.*?)</title>", REG_EXTENDED);
                if (regexec(&regex, s.ptr, 2, pmatch, 0) == 0) {
                    int start = pmatch[1].rm_so;
                    int end = pmatch[1].rm_eo;
                    char title[end - start + 1];
                    strncpy(title, s.ptr + start, end - start);
                    title[end - start] = '\0';
                    printf("%s
", title);
                }
                regfree(&regex);
            }
            free(s.ptr);
        }
        curl_global_cleanup();
    }
    return 0;
}