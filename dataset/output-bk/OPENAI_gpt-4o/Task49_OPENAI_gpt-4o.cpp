#include <iostream>
#include <string>
#include <sqlite3.h>
#include <httplib.h>

void store_data(const std::string& data) {
    sqlite3* db;
    char* errmsg;
    int rc = sqlite3_open("userdata.db", &db);
    if (rc) {
        sqlite3_close(db);
        return;
    }
    std::string sql = "CREATE TABLE IF NOT EXISTS Users (Data TEXT);";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return;
    }
    sqlite3_stmt* stmt;
    sql = "INSERT INTO Users (Data) VALUES (?);";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, data.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
}

int main() {
    httplib::Server svr;
    svr.Post("/store", [](const httplib::Request& req, httplib::Response& res) {
        store_data(req.body);
        res.set_content("Data stored successfully", "text/plain");
    });
    svr.listen("localhost", 8080);
    return 0;
}