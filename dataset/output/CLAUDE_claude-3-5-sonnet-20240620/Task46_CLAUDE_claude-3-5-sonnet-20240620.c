
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_LENGTH 100

void createTable(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS users "
                      "(name TEXT, email TEXT PRIMARY KEY, password TEXT);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void registerUser(sqlite3 *db) {
    char name[MAX_LENGTH], email[MAX_LENGTH], password[MAX_LENGTH];

    printf("Enter your name: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\\n")] = 0;

    printf("Enter your email: ");
    fgets(email, MAX_LENGTH, stdin);
    email[strcspn(email, "\\n")] = 0;

    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\\n")] = 0;

    char *sql = "INSERT INTO users (name, email, password) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, email, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, password, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            fprintf(stderr, "Execution failed: %s\\n", sqlite3_errmsg(db));
        } else {
            printf("Registration successful!\\n");
        }
    } else {
        fprintf(stderr, "SQL error: %s\\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("users.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\\n", sqlite3_errmsg(db));
        return 1;
    }

    createTable(db);
    registerUser(db);

    sqlite3_close(db);
    return 0;
}
