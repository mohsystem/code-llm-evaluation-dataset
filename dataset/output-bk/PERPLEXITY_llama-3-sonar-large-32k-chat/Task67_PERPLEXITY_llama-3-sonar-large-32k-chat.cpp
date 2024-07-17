#include <iostream>
#include <mysql.h>
#include <string>

struct Customer {
    std::string username;
    std::string name;
    std::string email;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <customerusername>" << std::endl;
        return 1;
    }
    std::string customerUsername = argv[1];
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[1024];

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "mydb", 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    sprintf(query, "SELECT * FROM customer WHERE username = '%s'", customerUsername.c_str());
    if (mysql_query(conn, query)) {
        std::cerr << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_use_result(conn);
    if ((row = mysql_fetch_row(res))) {
        Customer customer;
        customer.username = row[0];
        customer.name = row[1];
        customer.email = row[2];
        std::cout << "Customer: username=" << customer.username << ", name=" << customer.name << ", email=" << customer.email << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}