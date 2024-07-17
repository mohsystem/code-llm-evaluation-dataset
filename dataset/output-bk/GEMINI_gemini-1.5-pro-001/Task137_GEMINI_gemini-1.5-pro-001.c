#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errmsg = 0;
    int rc;

    rc = sqlite3_open("mydatabase.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s
", sqlite3_errmsg(db));
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
        fprintf(stderr, "SQL error: %s
", errmsg);
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    // Insert some sample data
    rc = sqlite3_exec(db, "INSERT INTO products (name, description, price) VALUES ('Apple', 'A sweet red fruit', 1.00)", 0, 0, &errmsg);
    rc = sqlite3_exec(db, "INSERT INTO products (name, description, price) VALUES ('Banana', 'A yellow curved fruit', 0.50)", 0, 0, &errmsg);
    rc = sqlite3_exec(db, "INSERT INTO products (name, description, price) VALUES ('Milk', 'A white dairy drink', 2.50)", 0, 0, &errmsg);

    while (1) {
        char productName[100];
        printf("Enter a product name (or 'quit' to exit): ");
        scanf("%s", productName);
        if (strcmp(productName, "quit") == 0) {
            break;
        }

        char sql[200];
        sprintf(sql, "SELECT * FROM products WHERE name = '%s'", productName);
        sqlite3_stmt* stmt;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s
", sqlite3_errmsg(db));
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            printf("Product details:
");
            printf("  ID: %d
", sqlite3_column_int(stmt, 0));
            printf("  Name: %s
", sqlite3_column_text(stmt, 1));
            printf("  Description: %s
", sqlite3_column_text(stmt, 2));
            printf("  Price: %f
", sqlite3_column_double(stmt, 3));
        } else {
            printf("Product '%s' not found.
", productName);
        }

        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return 0;
}