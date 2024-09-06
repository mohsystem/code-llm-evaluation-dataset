// Note: This code uses the mysql-connector-cpp library, which is not a standard C++ library.
// You need to install it and link it to your project.

#include <mysql/mysql.h>
#include <iostream>
#include <string>

int main() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0)) {
        std::cout << "Error connecting to database" << std::endl;
        return 1;
    }
    std::string query = "SELECT * FROM users WHERE username = '" + username + "'";
    if (mysql_query(conn, query.c_str())) {
        std::cout << "Error executing query" << std::endl;
        return 1;
    }
    res = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res)) != NULL) {
        std::cout << "User found: " << row[0] << ", " << row[1] << std::endl;
    } else {
        std::cout << "User not found" << std::endl;
    }
    mysql_close(conn);
    return 0;
}