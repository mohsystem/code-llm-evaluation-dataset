#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <openssl/sha.h>

char* hashPassword(const char* password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    char* hashString = malloc((SHA256_DIGEST_LENGTH * 2) + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashString + (i * 2), "%02x", hash[i]);
    }
    return hashString;
}

void updatePassword(const char* username, const char* new_password) {
    sqlite3 *db;
    sqlite3_open("users.db", &db);
    sqlite3_stmt *stmt;
    char* query = "UPDATE users SET password = ? WHERE username = ?";
    sqlite3_prepare_v2(db, query, strlen(query), &stmt, 0);
    sqlite3_bind_text(stmt, 1, hashPassword(new_password), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, username, -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    char username[256], new_password[256];
    printf("Enter username: ");
    fgets(username, 256, stdin);
    username[strcspn(username, "\n")] = 0; // remove newline
    printf("Enter new password: ");
    fgets(new_password, 256, stdin);
    new_password[strcspn(new_password, "\n")] = 0; // remove newline
    updatePassword(username, new_password);
    return 0;
}