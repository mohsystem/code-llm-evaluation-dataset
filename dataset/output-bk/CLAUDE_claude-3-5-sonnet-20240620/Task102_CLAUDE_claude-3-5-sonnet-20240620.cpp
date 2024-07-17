
#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

std::string hashPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill(\'0\') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

void updatePasswordInDatabase(const std::string& username, const std::string& hashedPassword) {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::PreparedStatement* pstmt;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password");
        con->setSchema("your_database");

        pstmt = con->prepareStatement("UPDATE users SET password = ? WHERE username = ?");
        pstmt->setString(1, hashedPassword);
        pstmt->setString(2, username);

        int rowsAffected = pstmt->executeUpdate();
        if (rowsAffected > 0) {
            std::cout << "Password updated successfully." << std::endl;
        } else {
            std::cout << "User not found." << std::endl;
        }

        delete pstmt;
        delete con;
    } catch (sql::SQLException& e) {
        std::cout << "SQL Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter new password: ";
    std::getline(std::cin, password);

    std::string hashedPassword = hashPassword(password);
    updatePasswordInDatabase(username, hashedPassword);

    return 0;
}
