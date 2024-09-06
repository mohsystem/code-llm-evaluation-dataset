#include <iostream>
#include <sqlite3.h>

using namespace std;

struct Customer {
    string customerusername;
    string customerfirstname;
    // Add other fields as needed
};

Customer get_customer_info(const string& customerusername) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    Customer customer;

    rc = sqlite3_open("your_database.db", &db); // Replace 'your_database.db'
    if (rc != SQLITE_OK) {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        return customer; // Return empty customer on error
    }

    string sql = "SELECT * FROM customer WHERE customerusername = ?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return customer; // Return empty customer on error
    }

    sqlite3_bind_text(stmt, 1, customerusername.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        customer.customerusername = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        customer.customerfirstname = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        // Fetch other fields as needed
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return customer;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <customerusername>" << endl;
        return 1;
    }

    string customerusername = argv[1];
    Customer customer = get_customer_info(customerusername);

    if (!customer.customerusername.empty()) {
        cout << "Customer Username: " << customer.customerusername << endl;
        cout << "Customer First Name: " << customer.customerfirstname << endl;
        // Output other fields
    } else {
        cout << "No customer found with username: " << customerusername << endl;
    }

    return 0;
}