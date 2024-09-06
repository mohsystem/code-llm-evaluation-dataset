#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <curl/curl.h>
#include <gumbo.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void search_for_list_items(GumboNode* node, std::vector<std::string>& data) {
    if (node->type != GUMBO_NODE_ELEMENT) return;
    if (node->v.element.tag == GUMBO_TAG_LI) {
        if (node->v.element.children.length == 1) {
            GumboNode* text = static_cast<GumboNode*>(node->v.element.children.data[0]);
            if (text->type == GUMBO_NODE_TEXT) {
                data.push_back(text->v.text.text);
            }
        }
    }
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        search_for_list_items(static_cast<GumboNode*>(children->data[i]), data);
    }
}

std::vector<std::string> scrapeData(const std::string& url) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    const char* html = readBuffer.c_str();
    GumboOutput* output = gumbo_parse(html);
    std::vector<std::string> data;
    search_for_list_items(output->root, data);
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    return data;
}

void storeData(const std::string& dbName, const std::vector<std::string>& data) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(dbName.c_str(), &db);
    if(rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    } else {
        std::cerr << "Opened database successfully" << std::endl;
    }

    const char* sqlCreate = "CREATE TABLE IF NOT EXISTS scraped_data (content TEXT);";
    rc = sqlite3_exec(db, sqlCreate, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    const char* sqlInsert = "INSERT INTO scraped_data (content) VALUES (?);";
    sqlite3_stmt *stmt;
    if(sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement" << std::endl;
        return;
    }

    for(const std::string& item : data) {
        sqlite3_bind_text(stmt, 1, item.c_str(), item.length(), SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    std::string url = "https://example.com";
    std::string dbName = "scraped_data.db";
    std::vector<std::string> data = scrapeData(url);
    storeData(dbName, data);
    return 0;
}