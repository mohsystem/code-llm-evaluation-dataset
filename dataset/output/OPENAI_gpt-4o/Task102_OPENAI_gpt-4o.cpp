// C++ code to accept username and password, hash the password, and update the database
// Comment: Complete implementation for a database connection in C++ can be complex and might require additional libraries. This is a simplistic representation.

#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <sqlite3.h>

std::string hashPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool updatePassword(const std::string& username, const std::string& password) {
    sqlite3* db;
    char* errMsg = 0;
    int exit = sqlite3_open("users.db", &db);

    std::string hashedPassword = hashPassword(password);
    std::string sql = "CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT);";
    sqlite3_exec(db, sql.c_str(), NULL, 0, &errMsg);

    sql = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "';";
    exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &errMsg);

    sqlite3_close(db);
    return exit == SQLITE_OK;
}

int main() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;
    if (updatePassword(username, password)) {
        std::cout << "Password updated successfully!" << std::endl;
    } else {
        std::cout << "Failed to update password." << std::endl;
    }
    return 0;
}