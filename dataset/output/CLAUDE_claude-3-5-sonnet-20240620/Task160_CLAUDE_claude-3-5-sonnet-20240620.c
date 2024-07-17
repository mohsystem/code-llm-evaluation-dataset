
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\
");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = \'\\0\';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\
");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = \'\\0\';
    s->len = new_len;

    return size*nmemb;
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    char url[256];

    printf("Enter a URL: ");
    if (fgets(url, sizeof(url), stdin) == NULL) {
        fprintf(stderr, "Error reading input\
");
        return 1;
    }
    url[strcspn(url, "\
")] = 0;  // Remove newline if present

    struct string s;
    init_string(&s);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "An error occurred: %s\
", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("Status code: %ld\
", response_code);
            printf("Response content:\
%s\
", s.ptr);
        }

        curl_easy_cleanup(curl);
    }

    free(s.ptr);

    return 0;
}
