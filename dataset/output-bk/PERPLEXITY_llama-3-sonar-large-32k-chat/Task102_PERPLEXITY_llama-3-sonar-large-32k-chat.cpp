#include <iostream>
#include <string>
#include <mysql/mysql.h>

std::string hashPassword(const std::string& password) {
    // Simple hashing example, in real-world scenarios use a secure hashing algorithm like bcrypt
    return std::to_string(password.length());
}

int main() {
    std::string username;
    std::string password;
    std::string hashedPassword;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter new password: ";
    std::getline(std::cin, password);

    hashedPassword = hashPassword(password);

    mysql_init(NULL);
    MYSQL* conn;
    conn = mysql_real_connect(NULL, "localhost", "root", "password", "mydb", 0, NULL, 0);
    if (!conn) {
        std::cerr << "Error connecting to database: " << mysql_error(conn) << std::endl;
        return 1;
    }

    std::string query = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "'";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Error updating password: " << mysql_error(conn) << std::endl;
        return 1;
    }

    std::cout << "Password updated successfully!" << std::endl;

    mysql_close(conn);
    return 0;
}