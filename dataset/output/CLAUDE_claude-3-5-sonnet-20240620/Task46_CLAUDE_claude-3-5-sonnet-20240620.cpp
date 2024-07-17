
#include <iostream>
#include <string>
#include <sqlite3.h>

int main() {
    std::string name, email, password;
    sqlite3 *db;
    char *err_msg = 0;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);
    
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);
    
    int rc = sqlite3_open("users.db", &db);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }
    
    std::string sql = "CREATE TABLE IF NOT EXISTS users (name TEXT, email TEXT, password TEXT);"
                      "INSERT INTO users (name, email, password) VALUES (?, ?, ?);";
    
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }
    
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }
    
    std::cout << "User registered successfully!" << std::endl;
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}
