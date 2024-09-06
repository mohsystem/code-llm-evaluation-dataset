
#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

void createTable(sqlite3* db) {
    char* errMsg = 0;
    const char* sql = "CREATE TABLE IF NOT EXISTS products "
                      "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT, "
                      "price REAL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void addProduct(sqlite3* db, const string& name, double price) {
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO products (name, price) VALUES (?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 2, price);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            cerr << "Execution failed: " << sqlite3_errmsg(db) << endl;
        }
    } else {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

void getProduct(sqlite3* db, int id) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT * FROM products WHERE id = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            cout << "ID: " << sqlite3_column_int(stmt, 0)
                 << ", Name: " << sqlite3_column_text(stmt, 1)
                 << ", Price: $" << sqlite3_column_double(stmt, 2) << endl;
        } else {
            cout << "Product not found." << endl;
        }
    } else {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;
    int rc = sqlite3_open("products.db", &db);

    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }

    createTable(db);

    while (true) {
        cout << "\\n1. Add product" << endl;
        cout << "2. Get product details" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double price;
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter product price: ";
                cin >> price;
                addProduct(db, name, price);
                cout << "Product added successfully!" << endl;
                break;
            }
            case 2: {
                int id;
                cout << "Enter product ID: ";
                cin >> id;
                getProduct(db, id);
                break;
            }
            case 3:
                sqlite3_close(db);
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
