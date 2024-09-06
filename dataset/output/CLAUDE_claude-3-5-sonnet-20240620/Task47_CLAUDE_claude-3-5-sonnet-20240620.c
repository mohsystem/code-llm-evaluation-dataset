
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sqlite3.h>

#define MAX_BUFFER 1048576 // 1MB
#define MAX_ITEMS 1000
#define MAX_ITEM_LENGTH 1000

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr) {
        printf("Not enough memory (realloc returned NULL)\\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

void scrapeWebsite(const char* url, char data[MAX_ITEMS][MAX_ITEM_LENGTH], int* count) {
    CURL *curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    res = curl_easy_perform(curl_handle);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\\n", curl_easy_strerror(res));
    } else {
        // Very basic parsing (for demonstration purposes)
        char* start = chunk.memory;
        while ((start = strstr(start, "<p>")) != NULL) {
            start += 3;
            char* end = strstr(start, "</p>");
            if (end != NULL) {
                int length = end - start;
                if (length < MAX_ITEM_LENGTH && *count < MAX_ITEMS) {
                    strncpy(data[*count], start, length);
                    data[*count][length] = '\\0';
                    (*count)++;
                }
                start = end + 4;
            } else {
                break;
            }
        }
    }

    curl_easy_cleanup(curl_handle);
    free(chunk.memory);
    curl_global_cleanup();
}

void storeInDatabase(char data[MAX_ITEMS][MAX_ITEM_LENGTH], int count) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("scraped_data.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS scraped_text(id INTEGER PRIMARY KEY, content TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\\n", err_msg);
        sqlite3_free(err_msg);
    }

    for (int i = 0; i < count; i++) {
        sql = "INSERT INTO scraped_text (content) VALUES (?);";
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

        if (rc == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, data[i], -1, SQLITE_STATIC);
            sqlite3_step(stmt);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
}

int main(void) {
    const char* url = "https://example.com"; // Replace with the website you want to scrape
    char scrapedData[MAX_ITEMS][MAX_ITEM_LENGTH];
    int count = 0;

    scrapeWebsite(url, scrapedData, &count);
    storeInDatabase(scrapedData, count);

    printf("Data scraped and stored successfully.\\n");
    return 0;
}
