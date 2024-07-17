#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;
    sqlite3_stmt *stmt;

    rc = sqlite3_open(":memory:", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    const char *sql = "CREATE TABLE product (id INTEGER PRIMARY KEY, name TEXT, price REAL);"
                      "INSERT INTO product (name, price) VALUES ('Apple', 1.0);"
                      "INSERT INTO product (name, price) VALUES ('Banana', 0.5);"
                      "INSERT INTO product (name, price) VALUES ('Cherry', 2.0);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }

    std::string product_name;
    std::cout << "Enter product name: ";
    std::cin >> product_name;

    const char *query = "SELECT * FROM product WHERE name=?";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        std::cout << "Product ID: " << sqlite3_column_int(stmt, 0)
                  << ", Name: " << sqlite3_column_text(stmt, 1)
                  << ", Price: " << sqlite3_column_double(stmt, 2) << std::endl;
    } else {
        std::cout << "Product not found." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}