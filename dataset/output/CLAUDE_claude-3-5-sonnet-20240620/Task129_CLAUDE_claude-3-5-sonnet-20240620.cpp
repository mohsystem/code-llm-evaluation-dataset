
#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void retrieveFile(const std::string& filename) {
    std::string serverUrl = "http://example.com/files/";  // Replace with actual server URL
    std::string fileUrl = serverUrl + filename;
    
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, fileUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        if (res == CURLE_OK) {
            std::ofstream outFile(filename, std::ios::binary);
            if (outFile.is_open()) {
                outFile.write(readBuffer.c_str(), readBuffer.size());
                outFile.close();
                std::cout << "File \'" << filename << "\' successfully retrieved and saved." << std::endl;
            } else {
                std::cerr << "Error: Unable to save file." << std::endl;
            }
        } else {
            std::cerr << "Error: Failed to retrieve file." << std::endl;
        }
    } else {
        std::cerr << "Error: Failed to initialize CURL." << std::endl;
    }
}

int main() {
    std::string userFilename;
    std::cout << "Enter the filename to retrieve: ";
    std::getline(std::cin, userFilename);
    retrieveFile(userFilename);
    return 0;
}
