
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_LENGTH 100

int main() {
    char name[MAX_LENGTH], email[MAX_LENGTH], password[MAX_LENGTH];
    sqlite3 *db;
    char *err_msg = 0;
    
    printf("Enter your name: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\
")] = 0;
    
    printf("Enter your email: ");
    fgets(email, MAX_LENGTH, stdin);
    email[strcspn(email, "\
")] = 0;
    
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\
")] = 0;
    
    int rc = sqlite3_open("users.db", &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\
", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    char *sql = "CREATE TABLE IF NOT EXISTS users (name TEXT, email TEXT, password TEXT);"
                "INSERT INTO users (name, email, password) VALUES (?, ?, ?);";
    
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\
", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password, -1, SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\
", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    printf("User registered successfully!\
");
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}
