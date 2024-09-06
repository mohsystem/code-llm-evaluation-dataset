// C++ (using CPP-HTTPLIB)
#include <httplib.h>
#include <sqlite3.h>
#include <nlohmann/json.hpp>

int main() {
    httplib::Server svr;

    svr.Post("/user", [](const httplib::Request &req, httplib::Response &res) {
        auto json = nlohmann::json::parse(req.body);
        sqlite3 *db;
        int rc = sqlite3_open("test.db", &db);
        if (rc) {
            res.status = 500;
            return;
        }
        char *zErrMsg = 0;
        std::string sql = "INSERT INTO users(name, email) VALUES('" + json["name"].get<std::string>() + "', '" + json["email"].get<std::string>() + "');";
        rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            res.status = 500;
        } else {
            res.status = 200;
            res.set_content("User added successfully", "text/plain");
        }
        sqlite3_close(db);
    });

    svr.listen("localhost", 8080);
}