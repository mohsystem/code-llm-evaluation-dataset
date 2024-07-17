#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) {
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';

    return realsize;
}

Json::Value fetchJsonFromUrl(const std::string& url) {
    CURL *curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = (char *)malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_handle = curl_easy_init();

    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl_handle);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s
", curl_easy_strerror(res));
            return Json::nullValue;
        }

        Json::CharReaderBuilder reader;
        Json::Value jsonObject;
        std::string errs;
        std::istringstream s(chunk.memory);
        std::string doc;
        s >> doc;
        std::istringstream docstream(doc);
        std::string errs;
        parseFromStream(builder, docstream, &jsonObject, &errs);

        curl_easy_cleanup(curl_handle);
        free(chunk.memory);
        curl_global_cleanup();

        return jsonObject;
    }

    return Json::nullValue;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <URL>" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    Json::Value jsonObject = fetchJsonFromUrl(url);

    Json::StreamWriterBuilder writer;
    std::string strJson = Json::writeString(writer, jsonObject);

    std::cout << strJson << std::endl;

    return 0;
}