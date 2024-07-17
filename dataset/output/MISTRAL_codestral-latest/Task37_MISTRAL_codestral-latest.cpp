// C++
#include <mysql.h>
#include <iostream>
#include <cstring>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "localhost";
    const char *user = "username";
    const char *password = "password";
    const char *database = "myDatabase";

    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    std::string query = "SELECT * FROM Users WHERE username = '" + username + "'";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_use_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL)
        std::cout << row[0] << " " << row[1] << std::endl;

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}