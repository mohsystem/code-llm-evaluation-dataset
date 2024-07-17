#include <mysql/mysql.h>
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <customerusername>" << std::endl;
        return 1;
    }
    const char *server = "localhost";
    const char *user = "root";
    const char *password = "password";
    const char *database = "yourdb";
    const char *username = argv[1];

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    std::string query = "SELECT * FROM customer WHERE username = '" + std::string(username) + "'";
    
    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res))) {
        std::cout << "ID: " << row[0] << std::endl;
        std::cout << "Username: " << row[1] << std::endl;
        std::cout << "Name: " << row[2] << std::endl;
        std::cout << "Email: " << row[3] << std::endl;
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}