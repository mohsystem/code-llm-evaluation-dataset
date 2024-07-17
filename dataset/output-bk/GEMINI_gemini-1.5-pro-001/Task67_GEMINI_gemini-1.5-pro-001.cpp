#include <iostream>
#include <string>
#include <mysql++/mysql++.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <customerusername>" << endl;
        return 1;
    }

    string customerUsername = argv[1];
    string dbHost = "localhost";
    string dbUser = "your_username";
    string dbPass = "your_password";
    string dbName = "your_database_name";

    try {
        mysqlpp::Connection conn(false);
        conn.connect(dbName.c_str(), dbHost.c_str(), dbUser.c_str(), dbPass.c_str());

        mysqlpp::Query query = conn.query();
        query << "SELECT * FROM customer WHERE customerusername = '" << customerUsername << "'";

        mysqlpp::StoreQueryResult res = query.store();

        if (res) {
            cout << "Customer Information:" << endl;
            mysqlpp::Row row = res.fetch_row();
            // Assuming customer table has columns: customerusername, firstname, lastname, email
            cout << "Username: " << row["customerusername"] << endl;
            cout << "First Name: " << row["firstname"] << endl;
            cout << "Last Name: " << row["lastname"] << endl;
            cout << "Email: " << row["email"] << endl;
        } else {
            cout << "Customer not found." << endl;
        }
    } catch (const mysqlpp::Exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}