#include <iostream>
#include <mysql/mysql.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <customer_username>" << std::endl;
        return 1;
    }
    std::string username = argv[1];
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0)) {
        std::cout << "Error: " << mysql_error(conn) << std::endl;
        return 1;
    }
    std::string query = "SELECT * FROM customer WHERE customerusername = '" + username + "'";
    if (mysql_query(conn, query.c_str())) {
        std::cout << "Error: " << mysql_error(conn) << std::endl;
        return 1;
    }
    res = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res))) {
        std::cout << row[0] << " " << row[1] << " ..." << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}