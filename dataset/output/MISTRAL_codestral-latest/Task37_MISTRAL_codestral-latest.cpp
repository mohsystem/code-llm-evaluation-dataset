// C++ code using MySQL Connector/C++
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>

int main() {
    try {
        // Create a connection
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");

        // Connect to the database
        con->setSchema("my_database");

        // Get username from user
        std::string username;
        std::cout << "Enter username: ";
        std::getline(std::cin, username);

        // Execute the query
        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("SELECT * FROM users WHERE username = ?");
        pstmt->setString(1, username);
        sql::ResultSet *res = pstmt->executeQuery();

        // Print the results
        while (res->next()) {
            std::cout << res->getInt(1) << " " << res->getString(2) << " " << res->getString(3) << std::endl;
        }

        // Close the connection
        delete res;
        delete pstmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    return 0;
}