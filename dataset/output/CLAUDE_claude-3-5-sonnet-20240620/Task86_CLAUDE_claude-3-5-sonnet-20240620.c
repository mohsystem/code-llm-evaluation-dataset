
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void download_file(const char* url, const char* filename) {
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

int main() {
    char url[1000];
    char filename[256];
    
    printf("Enter the URL of the EXE file: ");
    scanf("%999s", url);

    const char* last_slash = strrchr(url, '/');
    if (last_slash) {
        strcpy(filename, last_slash + 1);
    } else {
        strcpy(filename, "downloaded.exe");
    }

    download_file(url, filename);

    #ifdef _WIN32
        ShellExecute(NULL, "open", filename, NULL, NULL, SW_SHOWNORMAL);
    #else
        char chmod_cmd[300];
        sprintf(chmod_cmd, "chmod +x %s", filename);
        system(chmod_cmd);

        char exec_cmd[300];
        sprintf(exec_cmd, "./%s", filename);
        system(exec_cmd);
    #endif

    return 0;
}
