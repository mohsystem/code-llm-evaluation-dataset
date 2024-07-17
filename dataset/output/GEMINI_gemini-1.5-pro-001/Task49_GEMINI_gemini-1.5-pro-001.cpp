#include <iostream>
#include <string>
#include <vector>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <sqlite3.h>

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

// Callback function for SQLite queries
int callback(void* data, int argc, char** argv, char** azColName) {
    return 0;
}

int main() {
    // Connect to in-memory SQLite database
    sqlite3* db;
    char* err_msg = 0;
    int rc = sqlite3_open(":memory:", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Create the users table
    std::string sql = "CREATE TABLE IF NOT EXISTS users ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT NOT NULL,"
                      "email TEXT NOT NULL UNIQUE"
                      ");";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Create an HTTP listener
    http_listener listener("http://localhost:8080/users");

    listener.support(methods::POST, [&db](http_request request) {
        request.extract_json().then([&db](pplx::task<json::value> task) {
            try {
                auto json_data = task.get();
                auto name = json_data.at(U("name")).as_string();
                auto email = json_data.at(U("email")).as_string();

                // Insert the new user into the database
                std::string sql = "INSERT INTO users(name, email) VALUES('" +
                                  conversions::to_utf8string(name) + "', '" +
                                  conversions::to_utf8string(email) + "');";

                char* err_msg = 0;
                int rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err_msg);

                if (rc != SQLITE_OK) {
                    if (err_msg != nullptr && std::string(err_msg).find("UNIQUE constraint failed") != std::string::npos) {
                        request.reply(status_codes::BadRequest, "Email address already exists").wait();
                    } else {
                        request.reply(status_codes::InternalError, "Failed to create user").wait();
                    }
                    sqlite3_free(err_msg);
                    return;
                }

                request.reply(status_codes::Created, "User created successfully").wait();
            } catch (const json::json_exception& e) {
                request.reply(status_codes::BadRequest, "Invalid JSON data").wait();
            } catch (const std::exception& e) {
                request.reply(status_codes::InternalError, "Failed to process request").wait();
            }
        });
    });

    // Start listening for requests
    try {
        listener
            .open()
            .then([&listener]() { std::cout << "Starting to listen for requests at: " << listener.uri().to_string() << std::endl; })
            .wait();

        // Keep the program running
        while (true);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}