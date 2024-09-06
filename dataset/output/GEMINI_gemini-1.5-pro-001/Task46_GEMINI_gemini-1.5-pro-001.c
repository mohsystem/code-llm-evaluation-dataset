#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("users.db", &db);
    if (rc) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    char *errmsg = 0;
    rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "name TEXT NOT NULL,"
                          "email TEXT NOT NULL UNIQUE,"
                          "password TEXT NOT NULL"
                          ")", 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", errmsg);
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    char name[256], email[256], password[256];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline
    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // remove trailing newline
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // remove trailing newline

    char sql[512];
    sprintf(sql, "INSERT INTO users (name, email, password) VALUES ('%s', '%s', '%s')", name, email, password);
    rc = sqlite3_exec(db, sql, 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        if (strstr(errmsg, "UNIQUE constraint failed") != NULL) {
            fprintf(stderr, "Error: Email already exists.\n");
        } else {
            fprintf(stderr, "Error inserting data: %s\n", errmsg);
        }
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    printf("Registration successful!\n");

    sqlite3_close(db);
    return 0;
}