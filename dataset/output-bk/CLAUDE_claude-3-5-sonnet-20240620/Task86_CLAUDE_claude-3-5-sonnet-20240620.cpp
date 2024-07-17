
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, std::ofstream *stream) {
    stream->write(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <URL>" << std::endl;
        return 1;
    }

    const char *url = argv[1];
    const char *filename = "downloaded.exe";
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        std::ofstream outfile(filename, std::ofstream::binary);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outfile);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        outfile.close();

        if (res != CURLE_OK) {
            std::cerr << "Download failed: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }
    }

    // Execute the file
    std::system(filename);

    return 0;
}
