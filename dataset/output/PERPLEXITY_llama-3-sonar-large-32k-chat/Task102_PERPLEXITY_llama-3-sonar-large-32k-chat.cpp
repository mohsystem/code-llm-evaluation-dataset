#include <iostream>
#include <string>
#include <sqlite3.h>
#include <openssl/sha.h>

std::string hashPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::string hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        hashString += buffer;
    }
    return hashString;
}

void updatePassword(const std::string& username, const std::string& new_password) {
    sqlite3 *db;
    sqlite3_open("users.db", &db);
    sqlite3_stmt *stmt;
    std::string query = "UPDATE users SET password = ? WHERE username = ?";
    sqlite3_prepare_v2(db, query.c_str(), query.size(), &stmt, 0);
    sqlite3_bind_text(stmt, 1, hashPassword(new_password).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, username.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    std::string username, new_password;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter new password: ";
    std::getline(std::cin, new_password);
    updatePassword(username, new_password);
    return 0;
}