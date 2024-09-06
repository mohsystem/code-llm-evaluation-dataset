#include <stdio.h>
#include <sqlite3.h>

void getUserByUsername(const char* username) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("example.db", &db); // Change to your actual database

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    const char* sql = "SELECT * FROM users WHERE username=?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("User: %s - Info: %s\n", sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    char username[50];
    printf("Enter username: ");
    scanf("%s", username);
    getUserByUsername(username);
    return 0;
}