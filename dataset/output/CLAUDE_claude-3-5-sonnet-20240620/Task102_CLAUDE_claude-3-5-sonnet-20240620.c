
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <sqlite3.h>

void hash_password(const char* password, char* hashed_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashed_password[i * 2], "%02x", hash[i]);
    }
    hashed_password[SHA256_DIGEST_LENGTH * 2] = '\\0';
}

void update_password(const char* username, const char* new_password) {
    char hashed_password[SHA256_DIGEST_LENGTH * 2 + 1];
    hash_password(new_password, hashed_password);

    sqlite3* db;
    char* err_msg = 0;

    if (sqlite3_open("users.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\\n", sqlite3_errmsg(db));
        return;
    }

    char* create_table_sql = "CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY, password TEXT);";
    if (sqlite3_exec(db, create_table_sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\\n", err_msg);
        sqlite3_free(err_msg);
    }

    char update_sql[256];
    snprintf(update_sql, sizeof(update_sql), "UPDATE users SET password = '%s' WHERE username = '%s';", hashed_password, username);
    if (sqlite3_exec(db, update_sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\\n", err_msg);
        sqlite3_free(err_msg);
    }

    if (sqlite3_changes(db) == 0) {
        char insert_sql[256];
        snprintf(insert_sql, sizeof(insert_sql), "INSERT INTO users (username, password) VALUES ('%s', '%s');", username, hashed_password);
        if (sqlite3_exec(db, insert_sql, 0, 0, &err_msg) != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\\n", err_msg);
            sqlite3_free(err_msg);
        }
    }

    sqlite3_close(db);
}

int main() {
    char username[100], new_password[100];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\\n")] = 0;

    printf("Enter new password: ");
    fgets(new_password, sizeof(new_password), stdin);
    new_password[strcspn(new_password, "\\n")] = 0;

    update_password(username, new_password);
    printf("Password updated successfully.\\n");

    return 0;
}
