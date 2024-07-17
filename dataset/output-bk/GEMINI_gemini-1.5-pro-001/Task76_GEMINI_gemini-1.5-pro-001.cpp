#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>

using namespace std;

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        cerr << "Not enough memory (realloc returned NULL)" << endl;
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

string getPageTitle(const string& url) {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk;

    chunk.memory = (char *)malloc(1); 
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        } else {
            string htmlContent(chunk.memory);
            regex titleRegex("<title>(.*?)</title>", regex_constants::icase);
            smatch match;
            if (regex_search(htmlContent, match, titleRegex)) {
                curl_easy_cleanup(curl);
                free(chunk.memory);
                return match[1].str();
            }
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    return "";
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <url>" << endl;
        return 1;
    }

    string url = argv[1];
    string title = getPageTitle(url);

    if (!title.empty()) {
        cout << title << endl;
    } else {
        cout << "Title not found." << endl;
    }

    return 0;
}