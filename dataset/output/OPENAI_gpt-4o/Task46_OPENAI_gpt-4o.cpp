#include <iostream>
#include <sqlite3.h>

void createTable() {
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open("users.db", &DB);
    std::string sql = "CREATE TABLE IF NOT EXISTS users ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NAME TEXT NOT NULL, "
                      "EMAIL TEXT NOT NULL, "
                      "PASSWORD TEXT NOT NULL);";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    sqlite3_close(DB);
}

void registerUser(std::string name, std::string email, std::string password) {
    sqlite3* DB;
    int exit = sqlite3_open("users.db", &DB);
    std::string sql = "INSERT INTO users (NAME, EMAIL, PASSWORD) VALUES ('" + name + "', '" + email + "', '" + password + "');";
    sqlite3_exec(DB, sql.c_str(), NULL, 0, nullptr);
    sqlite3_close(DB);
}

int main() {
    createTable();
    std::string name, email, password;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);
    registerUser(name, email, password);
    std::cout << "User registered successfully!" << std::endl;
    return 0;
}