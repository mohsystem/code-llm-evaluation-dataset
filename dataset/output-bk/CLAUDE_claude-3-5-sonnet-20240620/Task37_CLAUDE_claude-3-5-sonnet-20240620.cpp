
#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

int main() {
    try {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt;
        sql::ResultSet *res;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password");
        con->setSchema("your_database");

        std::string username;
        std::cout << "Enter username: ";
        std::getline(std::cin, username);

        pstmt = con->prepareStatement("SELECT * FROM users WHERE username = ?");
        pstmt->setString(1, username);
        res = pstmt->executeQuery();

        if (res->next()) {
            std::cout << "User ID: " << res->getInt("id") << std::endl;
            std::cout << "Username: " << res->getString("username") << std::endl;
            std::cout << "Email: " << res->getString("email") << std::endl;
        } else {
            std::cout << "User not found." << std::endl;
        }

        delete res;
        delete pstmt;
        delete con;

    } catch (sql::SQLException &e) {
        std::cout << "SQL Exception: " << e.what() << std::endl;
    }

    return 0;
}
