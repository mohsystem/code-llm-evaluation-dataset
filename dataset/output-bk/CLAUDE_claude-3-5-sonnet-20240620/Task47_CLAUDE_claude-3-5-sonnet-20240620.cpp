
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <sqlite3.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch(std::bad_alloc &e) {
        return 0;
    }
    return newLength;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            sqlite3 *db;
            char *zErrMsg = 0;
            int rc;

            rc = sqlite3_open("scraped_data.db", &db);

            if(rc) {
                std::cerr << "Can\'t open database: " << sqlite3_errmsg(db) << std::endl;
                return(0);
            }

            const char *sql = "CREATE TABLE IF NOT EXISTS scraped_data("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "CONTENT TEXT NOT NULL);";

            rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);

            if(rc != SQLITE_OK) {
                std::cerr << "SQL error: " << zErrMsg << std::endl;
                sqlite3_free(zErrMsg);
            }

            sql = "INSERT INTO scraped_data (CONTENT) VALUES (?);";
            sqlite3_stmt *stmt;
            rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

            if(rc != SQLITE_OK) {
                std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            } else {
                sqlite3_bind_text(stmt, 1, readBuffer.c_str(), readBuffer.length(), SQLITE_STATIC);
                rc = sqlite3_step(stmt);

                if(rc != SQLITE_DONE) {
                    std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
                } else {
                    std::cout << "Data scraped and stored successfully." << std::endl;
                }

                sqlite3_finalize(stmt);
            }

            sqlite3_close(db);
        }
    }

    return 0;
}
