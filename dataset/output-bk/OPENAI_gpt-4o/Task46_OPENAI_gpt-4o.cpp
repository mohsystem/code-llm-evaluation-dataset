#include <iostream>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "localhost";
    const char *user = "root";
    const char *password = "password";
    const char *database = "testdb";

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        exit(1);
    }

    std::string name, email, password_in;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter password: ";
    std::cin >> password_in;

    std::string query = "INSERT INTO users (name, email, password) VALUES ('" + name + "', '" + email + "', '" + password_in + "')";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        exit(1);
    }

    std::cout << "User registered successfully!" << std::endl;
    mysql_close(conn);
    return 0;
}