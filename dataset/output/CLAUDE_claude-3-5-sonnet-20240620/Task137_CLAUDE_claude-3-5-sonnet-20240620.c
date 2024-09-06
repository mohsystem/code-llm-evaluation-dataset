
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void createTable(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS products "
                      "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT, "
                      "price REAL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void addProduct(sqlite3 *db, const char *name, double price) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO products (name, price) VALUES (?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 2, price);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            fprintf(stderr, "Execution failed: %s\\n", sqlite3_errmsg(db));
        }
    } else {
        fprintf(stderr, "SQL error: %s\\n", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);
}

void getProduct(sqlite3 *db, int id) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM products WHERE id = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            printf("ID: %d, Name: %s, Price: $%.2f\\n",
                   sqlite3_column_int(stmt, 0),
                   sqlite3_column_text(stmt, 1),
                   sqlite3_column_double(stmt, 2));
        } else {
            printf("Product not found.\\n");
        }
    } else {
        fprintf(stderr, "SQL error: %s\\n", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("products.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\\n", sqlite3_errmsg(db));
        return 1;
    }

    createTable(db);

    while (1) {
        printf("\\n1. Add product\\n");
        printf("2. Get product details\\n");
        printf("3. Exit\\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[100];
                double price;
                printf("Enter product name: ");
                getchar(); // Consume newline
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\\n")] = 0; // Remove newline
                printf("Enter product price: ");
                scanf("%lf", &price);
                addProduct(db, name, price);
                printf("Product added successfully!\\n");
                break;
            }
            case 2: {
                int id;
                printf("Enter product ID: ");
                scanf("%d", &id);
                getProduct(db, id);
                break;
            }
            case 3:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice. Please try again.\\n");
        }
    }

    return 0;
}
