#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <curl/curl.h>
#include <gumbo.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t totalSize = size * nmemb;
    strcat(userp, (char*)contents);
    return totalSize;
}

void search_for_list_items(GumboNode* node, FILE* file) {
    if (node->type != GUMBO_NODE_ELEMENT) return;
    if (node->v.element.tag == GUMBO_TAG_LI) {
        if (node->v.element.children.length == 1) {
            GumboNode* text = node->v.element.children.data[0];
            if (text->type == GUMBO_NODE_TEXT) {
                fprintf(file, "%s,", text->v.text.text);
            }
        }
    }
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        search_for_list_items(children->data[i], file);
    }
}

void scrapeData(const char* url, const char* fileName) {
    CURL *curl;
    CURLcode res;
    char *readBuffer = malloc(1000000);
    memset(readBuffer, 0, 1000000);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    const char* html = readBuffer;
    GumboOutput* output = gumbo_parse(html);

    FILE* file = fopen(fileName, "w");
    search_for_list_items(output->root, file);
    fclose(file);

    gumbo_destroy_output(&kGumboDefaultOptions, output);
    free(readBuffer);
}

void storeData(const char* dbName, const char* fileName) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(dbName, &db);
    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    const char* sqlCreate = "CREATE TABLE IF NOT EXISTS scraped_data (content TEXT);";
    rc = sqlite3_exec(db, sqlCreate, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    const char* sqlInsert = "INSERT INTO scraped_data (content) VALUES (?);";
    sqlite3_stmt *stmt;
    if(sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement\n");
        return;
    }

    FILE* file = fopen(fileName, "r");
    char item[500];
    while(fscanf(file, "%499[^,],", item) == 1) {
        sqlite3_bind_text(stmt, 1, item, strlen(item), SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    fclose(file);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    const char* url = "https://example.com";
    const char* dbName = "scraped_data.db";
    const char* fileName = "scraped_data.txt";
    
    scrapeData(url, fileName);
    storeData(dbName, fileName);
    
    return 0;
}