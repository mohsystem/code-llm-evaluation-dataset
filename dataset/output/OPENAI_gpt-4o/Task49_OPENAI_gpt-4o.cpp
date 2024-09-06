#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
#include <sqlite3.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_post(http_request request) {
    request
        .extract_json()
        .then([&](json::value requestData) {
            auto name = requestData[U("name")].as_string();
            auto email = requestData[U("email")].as_string();

            sqlite3* db;
            sqlite3_open("example.db", &db);
            sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, email TEXT);", 0, 0, 0);

            std::string sql =
                "INSERT INTO users (name, email) VALUES ('" + name + "','" + email + "');";
            sqlite3_exec(db, sql.c_str(), 0, 0, 0);
            sqlite3_close(db);

            request.reply(status_codes::OK, json::value::string(U("User added successfully!")));
        })
        .wait();
}

int main() {
    http_listener listener(U("http://localhost:8080/add_user"));
    listener.support(methods::POST, handle_post);

    try {
        listener.open().wait();
        std::cout << "Listening on port 8080..." << std::endl;
        std::string line;
        std::getline(std::cin, line);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}