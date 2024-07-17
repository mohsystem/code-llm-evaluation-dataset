#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;
    sqlite3_stmt *stmt;

    rc = sqlite3_open(":memory:", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s
", sqlite3_errmsg(db));
        return rc;
    }

    const char *sql = "CREATE TABLE product (id INTEGER PRIMARY KEY, name TEXT, price REAL);"
                      "INSERT INTO product (name, price) VALUES ('Apple', 1.0);"
                      "INSERT INTO product (name, price) VALUES ('Banana', 0.5);"
                      "INSERT INTO product (name, price) VALUES ('Cherry', 2.0);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s
", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }

    char product_name[50];
    printf("Enter product name: ");
    scanf("%49s", product_name);

    const char *query = "SELECT * FROM product WHERE name=?";
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s
", sqlite3_errmsg(db));
        sqlite3_close(db);
        return rc;
    }

    sqlite3_bind_text(stmt, 1, product_name, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        printf("Product ID: %d, Name: %s, Price: %.2f
",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_double(stmt, 2));
    } else {
        printf("Product not found.
");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}