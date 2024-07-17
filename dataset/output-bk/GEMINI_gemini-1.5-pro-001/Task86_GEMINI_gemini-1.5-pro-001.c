#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#endif

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please provide a URL as an argument.
");
        return 1;
    }

    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = argv[1];
    char filename[FILENAME_MAX];
    const char *outfilename = "downloaded.exe";

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file for writing
");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        fclose(fp);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s
",
                    curl_easy_strerror(res));
            return 1;
        }
    }

    // Execute the downloaded file
    #ifdef _WIN32
    snprintf(filename, sizeof(filename), "%s", outfilename);
    WinExec(filename, SW_SHOW);
    #else
    snprintf(filename, sizeof(filename), "./%s", outfilename);
    execl(filename, filename, NULL);
    #endif

    return 0;
}