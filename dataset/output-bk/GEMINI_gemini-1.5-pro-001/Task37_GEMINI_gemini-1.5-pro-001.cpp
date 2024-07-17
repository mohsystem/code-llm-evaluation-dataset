#include <iostream>
#include <mysql++.h>

using namespace std;

int main() {
    try {
        mysqlx::Session session("localhost", 3306, "your_username", "your_password", "your_database_name");
        string username;

        cout << "Enter username: ";
        cin >> username;

        auto result = session.sql("SELECT * FROM users WHERE username = ?").bind(username).execute();

        for (auto row : result) {
            cout << "Username: " << row[0] << endl;
            cout << "Email: " << row[1] << endl;
            // Retrieve other user information as needed
        }

    } catch (const mysqlx::Error &err) {
        cerr << "Error: " << err << endl;
        return 1;
    }

    return 0;
}