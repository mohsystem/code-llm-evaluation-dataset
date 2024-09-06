#include <iostream>
#include <sqlite3.h>

void get_customer_info(const std::string &username) {
    sqlite3 *db;
    sqlite3_open("your_database.db", &db);
    std::string query = "SELECT * FROM customer WHERE username = ?";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), username.length(), SQLITE_STATIC);
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int col = 0; col < sqlite3_column_count(stmt); ++col) {
            std::cout << sqlite3_column_text(stmt, col) << " ";
        }
        std::cout << std::endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <customerusername>" << std::endl;
        return 1;
    }
    std::string username = argv[1];
    get_customer_info(username);
    return 0;
}