#include <stdio.h>
#include <sqlite3.h>

void createTable() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    rc = sqlite3_open("users.db", &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    char *sql = "CREATE TABLE IF NOT EXISTS users("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "NAME TEXT NOT NULL, "
                "EMAIL TEXT NOT NULL, "
                "PASSWORD TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
}

void registerUser(const char *name, const char *email, const char *password) {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    rc = sqlite3_open("users.db", &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    char sql[200];
    snprintf(sql, sizeof(sql), "INSERT INTO users (NAME, EMAIL, PASSWORD) VALUES ('%s', '%s', '%s');", name, email, password);

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);
}

int main(int argc, char* argv[]) {
    createTable();
    
    char name[50], email[50], password[50];

    printf("Enter your name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    printf("Enter your email: ");
    fgets(email, 50, stdin);
    email[strcspn(email, "\n")] = 0; // Remove trailing newline

    printf("Enter your password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0; // Remove trailing newline

    registerUser(name, email, password);

    printf("User registered successfully!\n");

    return 0;
}