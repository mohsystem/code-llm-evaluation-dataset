#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

// Callback function for cURL to write data to a string
size_t write_callback(void *contents, size_t size, size_t nmemb, char **buffer) {
    size_t newLength = size * nmemb;
    *buffer = (char *)realloc(*buffer, strlen(*buffer) + newLength + 1);
    if (*buffer == NULL) {
        fprintf(stderr, "Error: realloc failed\n");
        return 0;
    }
    memcpy(*buffer + strlen(*buffer), contents, newLength);
    (*buffer)[strlen(*buffer) + newLength] = '\0';
    return newLength;
}

// Function to extract title from HTML
char *extract_title(const char *html) {
    regex_t regex;
    regmatch_t match[2];
    char *title = NULL;
    int reti;

    // Compile regular expression
    reti = regcomp(&regex, "<title>(.*?)</title>", REG_ICASE | REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Error: Could not compile regex\n");
        return NULL;
    }

    // Execute regular expression
    reti = regexec(&regex, html, 2, match, 0);
    if (!reti) {
        // Extract matched substring
        int start = match[1].rm_so;
        int end = match[1].rm_eo;
        int title_len = end - start;
        title = (char *)malloc(title_len + 1);
        if (title == NULL) {
            fprintf(stderr, "Error: malloc failed\n");
            regfree(&regex);
            return NULL;
        }
        strncpy(title, html + start, title_len);
        title[title_len] = '\0';
    } else if (reti != REG_NOMATCH) {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Error: Regex match failed: %s\n", msgbuf);
    }

    regfree(&regex);
    return title;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];
    CURL *curl;
    CURLcode res;
    char *buffer = NULL;
    size_t buffer_len = 0;
    char *title = NULL;

    // Initialize cURL
    curl = curl_easy_init();
    if (curl) {
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set write callback function and data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        // Perform HTTP request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Extract title from HTML
            title = extract_title(buffer);
            if (title != NULL) {
                printf("%s\n", title);
                free(title);
            } else {
                fprintf(stderr, "Error: Could not extract title from HTML\n");
            }
        }

        // Clean up cURL
        curl_easy_cleanup(curl);

        // Free buffer
        if (buffer != NULL) {
            free(buffer);
        }
    } else {
        fprintf(stderr, "Error: Could not initialize cURL\n");
    }

    return 0;
}