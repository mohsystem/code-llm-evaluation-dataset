
#include <iostream>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <sqlite3.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class UserHandler {
public:
    UserHandler() {
        sqlite3_open("users.db", &db);
        const char* create_table_sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT);";
        sqlite3_exec(db, create_table_sql, nullptr, nullptr, nullptr);
    }

    ~UserHandler() {
        sqlite3_close(db);
    }

    void handle_post(http_request request) {
        request.extract_json().then([this](json::value body) {
            auto name = body["name"].as_string();
            auto email = body["email"].as_string();

            const char* insert_sql = "INSERT INTO users (name, email) VALUES (?, ?);";
            sqlite3_stmt* stmt;
            sqlite3_prepare_v2(db, insert_sql, -1, &stmt, nullptr);
            sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);

            json::value response;
            response["message"] = json::value::string("User created successfully");
            request.reply(status_codes::Created, response);
        });
    }

private:
    sqlite3* db;
};

int main() {
    http_listener listener("http://localhost:8080/api/users");
    UserHandler handler;

    listener.support(methods::POST, [&](http_request request) {
        handler.handle_post(request);
    });

    try {
        listener.open().wait();
        std::cout << "Listening on http://localhost:8080/api/users" << std::endl;
        while (true);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
