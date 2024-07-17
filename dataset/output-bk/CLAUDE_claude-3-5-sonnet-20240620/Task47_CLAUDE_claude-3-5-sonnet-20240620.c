
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sqlite3.h>

#define MAX_BUFFER 1024 * 1024 // 1MB buffer

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr) {
        printf("Not enough memory (realloc returned NULL)\
");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

int main(void) {
    CURL *curl_handle;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    sqlite3 *db;
    char *err_msg = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    if (curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl_handle);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\
", curl_easy_strerror(res));
        } else {
            int rc = sqlite3_open("scraped_data.db", &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Cannot open database: %s\
", sqlite3_errmsg(db));
                sqlite3_close(db);
                return 1;
            }

            char *sql = "CREATE TABLE IF NOT EXISTS scraped_data (id INTEGER PRIMARY KEY AUTOINCREMENT, content TEXT);";
            rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\
", err_msg);
                sqlite3_free(err_msg);
            }

            sql = "INSERT INTO scraped_data (content) VALUES (?);";
            sqlite3_stmt *stmt;
            rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Failed to prepare statement: %s\
", sqlite3_errmsg(db));
            } else {
                sqlite3_bind_text(stmt, 1, chunk.memory, chunk.size, SQLITE_STATIC);
                rc = sqlite3_step(stmt);

                if (rc != SQLITE_DONE) {
                    fprintf(stderr, "Execution failed: %s\
", sqlite3_errmsg(db));
                } else {
                    printf("Data scraped and stored successfully.\
");
                }

                sqlite3_finalize(stmt);
            }

            sqlite3_close(db);
        }

        curl_easy_cleanup(curl_handle);
    }

    free(chunk.memory);
    curl_global_cleanup();

    return 0;
}
