#include <mysql.h>
#include <iostream>
#include <string>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    std::string username;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "mydb", 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    std::string query = "SELECT * FROM users WHERE username = '" + username + "'";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_use_result(conn);
    while ((row = mysql_fetch_row(res))) {
        std::cout << "Username: " << row[0] << std::endl;
        std::cout << "Email: " << row[1] << std::endl;
        std::cout << "Password: " << row[2] << std::endl;
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}