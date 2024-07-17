#include <iostream>
#include <sqlite3.h>

using namespace std;

int main() {
    sqlite3* db;
    char* errmsg = 0;
    int rc;

    rc = sqlite3_open("mydatabase.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }

    // Create the products table if it doesn't exist
    const char* createTableSql = "CREATE TABLE IF NOT EXISTS products ("
                                "id INTEGER PRIMARY KEY,"
                                "name TEXT NOT NULL,"
                                "description TEXT,"
                                "price REAL)";
    rc = sqlite3_exec(db, createTableSql, 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errmsg << endl;
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    // Insert some sample data
    rc = sqlite3_exec(db, "INSERT INTO products (name, description, price) VALUES ('Apple', 'A sweet red fruit', 1.00)", 0, 0, &errmsg);
    rc = sqlite3_exec(db, "INSERT INTO products (name, description, price) VALUES ('Banana', 'A yellow curved fruit', 0.50)", 0, 0, &errmsg);
    rc = sqlite3_exec(db, "INSERT INTO products (name, description, price) VALUES ('Milk', 'A white dairy drink', 2.50)", 0, 0, &errmsg);

    while (true) {
        string productName;
        cout << "Enter a product name (or 'quit' to exit): ";
        cin >> productName;
        if (productName == "quit") {
            break;
        }

        string sql = "SELECT * FROM products WHERE name = '" + productName + "'";
        sqlite3_stmt* stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
        if (rc != SQLITE_OK) {
            cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << "Product details:" << endl;
            cout << "  ID: " << sqlite3_column_int(stmt, 0) << endl;
            cout << "  Name: " << sqlite3_column_text(stmt, 1) << endl;
            cout << "  Description: " << sqlite3_column_text(stmt, 2) << endl;
            cout << "  Price: " << sqlite3_column_double(stmt, 3) << endl;
        } else {
            cout << "Product '" << productName << "' not found." << endl;
        }

        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return 0;
}