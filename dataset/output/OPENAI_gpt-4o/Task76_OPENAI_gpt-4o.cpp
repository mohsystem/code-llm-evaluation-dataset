#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>

using namespace std;

struct Memory {
    char* response;
    size_t size;
};

static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total_size = size * nmemb;
    struct Memory* mem = (struct Memory*)userp;

    char* ptr = (char*)realloc(mem->response, mem->size + total_size + 1);
    if(ptr == NULL) {
        cout << "Not enough memory (realloc returned NULL)" << endl;
        return 0;
    }

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), contents, total_size);
    mem->size += total_size;
    mem->response[mem->size] = 0;

    return total_size;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        CURL* curl;
        CURLcode res;
        Memory chunk = {0};

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
            res = curl_easy_perform(curl);

            if(res == CURLE_OK) {
                string html(chunk.response);
                smatch match;
                regex pattern("<title>(.*?)</title>");
                if (regex_search(html, match, pattern) && match.size() > 1) {
                    cout << match.str(1) << endl;
                }
            }
            free(chunk.response);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }
    return 0;
}