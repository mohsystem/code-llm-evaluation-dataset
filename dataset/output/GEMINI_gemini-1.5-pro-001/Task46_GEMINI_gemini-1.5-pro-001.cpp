#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main() {
    try {
        sql::Driver *driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect("tcp://127.0.0.1:3306", "username", "password"));
        conn->setSchema("user_db");

        string name, email, password;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your email: ";
        getline(cin, email);
        cout << "Enter your password: ";
        getline(cin, password);

        std::unique_ptr<sql::PreparedStatement> stmt(conn->prepareStatement("INSERT INTO users (name, email, password) VALUES (?, ?, ?)"));
        stmt->setString(1, name);
        stmt->setString(2, email);
        stmt->setString(3, password);
        stmt->executeUpdate();

        cout << "Registration successful!" << endl;

    } catch (sql::SQLException &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}