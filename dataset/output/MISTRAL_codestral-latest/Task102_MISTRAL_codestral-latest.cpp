// C++ code using SQLite C/C++ Library for database operations and OpenSSL for password hashing
#include <sqlite3.h>
#include <openssl/sha.h>
#include <iostream>
#include <string>

void updatePassword(const std::string& username, const std::string& newPassword) {
    sqlite3* DB;
    int rc = sqlite3_open("user_database.db", &DB);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(DB) << std::endl;
        return;
    }

    // Hash the new password
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, newPassword.c_str(), newPassword.length());
    SHA256_Final(hash, &sha256);

    std::string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashedPassword += std::to_string(hash[i]);
    }

    // Update the password in the database
    std::string sql = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "';";
    char* errMsg = nullptr;
    rc = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_close(DB);
}

int main() {
    std::string username, newPassword;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your new password: ";
    std::cin >> newPassword;

    updatePassword(username, newPassword);

    return 0;
}