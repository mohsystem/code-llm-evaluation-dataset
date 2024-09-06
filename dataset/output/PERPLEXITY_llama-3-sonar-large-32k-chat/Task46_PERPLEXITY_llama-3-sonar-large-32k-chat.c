#include <stdio.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void createTable(sqlite3 *db) {
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (name TEXT, email TEXT PRIMARY KEY, password TEXT)", callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void registerUser(sqlite3 *db, const char *name, const char *email, const char *password) {
    char *zErrMsg = 0;
    char sql[200];
    sprintf(sql, "INSERT INTO users VALUES ('%s', '%s', '%s')", name, email, password);
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("users.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    createTable(db);
    char name[100], email[100], password[100];
    printf("Enter your name: ");
    fgets(name, 100, stdin);
    printf("Enter your email: ");
    fgets(email, 100, stdin);
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    registerUser(db, name, email, password);
    printf("User registered successfully!\n");
    sqlite3_close(db);
    return 0;
}