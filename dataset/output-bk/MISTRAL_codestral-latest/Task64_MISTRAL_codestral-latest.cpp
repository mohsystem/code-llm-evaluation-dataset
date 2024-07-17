#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

Json::Value read_json_from_url(const std::string &url) {
    CURL *curl;
    FILE *fp;
    char *data;
    long data_size;
    Json::Value root;
    Json::Reader reader;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen("temp.json", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();

    std::ifstream ifs("temp.json");
    reader.parse(ifs, root);
    ifs.close();

    remove("temp.json");

    return root;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please provide a URL as a command line argument.
";
        return 1;
    }

    std::string url = argv[1];
    Json::Value root = read_json_from_url(url);
    std::cout << root.toStyledString() << std::endl;

    return 0;
}