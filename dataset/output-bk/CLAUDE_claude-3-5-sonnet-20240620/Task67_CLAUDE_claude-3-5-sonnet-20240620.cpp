
#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please provide a customer username." << std::endl;
        return 1;
    }

    try {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt;
        sql::ResultSet *res;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password");
        con->setSchema("your_database");

        pstmt = con->prepareStatement("SELECT * FROM customer WHERE customerusername = ?");
        pstmt->setString(1, argv[1]);
        res = pstmt->executeQuery();

        if (res->next()) {
            std::cout << "Customer ID: " << res->getInt("customerid") << std::endl;
            std::cout << "Name: " << res->getString("name") << std::endl;
            std::cout << "Email: " << res->getString("email") << std::endl;
            std::cout << "Phone: " << res->getString("phone") << std::endl;
        } else {
            std::cout << "Customer not found." << std::endl;
        }

        delete res;
        delete pstmt;
        delete con;

    } catch (sql::SQLException &e) {
        std::cout << "SQL Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
