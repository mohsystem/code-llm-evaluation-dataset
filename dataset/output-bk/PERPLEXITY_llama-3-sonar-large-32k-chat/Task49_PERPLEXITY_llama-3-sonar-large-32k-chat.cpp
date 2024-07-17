#include <mysql.h>
#include <iostream>
#include <string>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    std::string server = "localhost";
    std::string user = "root";
    std::string password = "password";
    std::string database = "mydb";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), database.c_str(), 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    std::string query = "CREATE TABLE IF NOT EXISTS users (name VARCHAR(255), email VARCHAR(255))";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    std::cout << "Enter name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter email: ";
    std::string email;
    std::getline(std::cin, email);

    query = "INSERT INTO users (name, email) VALUES ('" + name + "', '" + email + "')";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    mysql_close(conn);
    return 0;
}