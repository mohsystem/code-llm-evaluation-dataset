#include <iostream>
#include <string>
#include <cpp_httplib/httplib.h>
#include <sqlite3.h>

using namespace std;
using namespace httplib;

int main(void) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // Open database
    rc = sqlite3_open("users.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return 1;
    } else {
        cout << "Opened database successfully" << endl;
    }

    // Create a table for users if it doesn't exist
    const char *sqlCreateTable = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE
        )
    )";
    rc = sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
        return 1;
    }

    Server svr;

    svr.Post("/users", [&db](const Request &req, Response &res) {
        if (!req.has_param("name") || !req.has_param("email")) {
            res.status = 400;
            res.set_content("Name and email are required", "text/plain");
            return;
        }

        string name = req.get_param_value("name");
        string email = req.get_param_value("email");

        string sqlInsert = "INSERT INTO users (name, email) VALUES ('" + name + "', '" + email + "')";
        char *zErrMsg = 0;
        int rc = sqlite3_exec(db, sqlInsert.c_str(), nullptr, nullptr, &zErrMsg);
        if (rc != SQLITE_OK) {
            if (string(zErrMsg).find("UNIQUE constraint failed") != string::npos) {
                res.status = 400;
                res.set_content("Email already exists", "text/plain");
            } else {
                res.status = 500;
                res.set_content("Failed to create user", "text/plain");
                cerr << "SQL error: " << zErrMsg << endl;
            }
            sqlite3_free(zErrMsg);
        } else {
            res.status = 201;
            res.set_content("User created successfully", "text/plain");
        }
    });

    svr.listen("localhost", 8080);

    sqlite3_close(db);
    return 0;
}