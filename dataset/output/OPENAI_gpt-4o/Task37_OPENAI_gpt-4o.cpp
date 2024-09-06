#include <iostream>
#include <sqlite3.h>

void getUserByUsername(const std::string& username) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("example.db", &db); // Change to your actual database

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::string sql = "SELECT * FROM users WHERE username=?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to execute statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        std::cout << "User: " << sqlite3_column_text(stmt, 1) << " - Info: " << sqlite3_column_text(stmt, 2) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;
    getUserByUsername(username);
    return 0;
}