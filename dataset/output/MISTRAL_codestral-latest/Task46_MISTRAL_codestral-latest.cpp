#include <mysql.h>
#include <iostream>
#include <string>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    std::string name, email, password;

    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter email: ";
    std::cin >> email;

    std::cout << "Enter password: ";
    std::cin >> password;

    std::string query = "INSERT INTO users (name, email, password) VALUES ('" + name + "', '" + email + "', '" + password + "')";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "mydb", 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        mysql_close(conn);
        exit(1);
    }

    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        mysql_close(conn);
        exit(1);
    }

    mysql_close(conn);

    return 0;
}