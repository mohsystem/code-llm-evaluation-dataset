
#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
#include <sqlite3.h>

// Callback function for cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

// Function to scrape website
std::vector<std::string> scrapeWebsite(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::vector<std::string> data;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            // Very basic parsing (for demonstration purposes)
            size_t pos = 0;
            while ((pos = readBuffer.find("<p>", pos)) != std::string::npos) {
                size_t end = readBuffer.find("</p>", pos);
                if (end != std::string::npos) {
                    data.push_back(readBuffer.substr(pos + 3, end - pos - 3));
                    pos = end + 4;
                } else {
                    break;
                }
            }
        }
    }
    return data;
}

// Function to store data in SQLite database
void storeInDatabase(const std::vector<std::string>& data) {
    sqlite3* db;
    char* errMsg = 0;
    int rc = sqlite3_open("scraped_data.db", &db);
    
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    const char* sql = "CREATE TABLE IF NOT EXISTS scraped_text(id INTEGER PRIMARY KEY, content TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    for (const auto& item : data) {
        sql = "INSERT INTO scraped_text (content) VALUES (?);";
        sqlite3_stmt* stmt;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        
        if (rc == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, item.c_str(), -1, SQLITE_STATIC);
            sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
}

int main() {
    std::string url = "https://example.com"; // Replace with the website you want to scrape
    std::vector<std::string> scrapedData = scrapeWebsite(url);
    storeInDatabase(scrapedData);
    std::cout << "Data scraped and stored successfully." << std::endl;
    return 0;
}
