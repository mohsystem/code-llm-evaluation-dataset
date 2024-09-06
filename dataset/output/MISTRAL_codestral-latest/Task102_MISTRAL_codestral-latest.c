// C code using SQLite C/C++ Library for database operations and OpenSSL for password hashing
// Note: C does not have built-in support for string manipulation, so this code may not work as expected
#include <sqlite3.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

void updatePassword(const char* username, const char* newPassword) {
    sqlite3* DB;
    int rc = sqlite3_open("user_database.db", &DB);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(DB));
        return;
    }

    // Hash the new password
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, newPassword, strlen(newPassword));
    SHA256_Final(hash, &sha256);

    char hashedPassword[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashedPassword[i * 2], "%02x", hash[i]);
    }

    // Update the password in the database
    char sql[256];
    sprintf(sql, "UPDATE users SET password = '%s' WHERE username = '%s';", hashedPassword, username);
    char* errMsg = NULL;
    rc = sqlite3_exec(DB, sql, NULL, NULL, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(DB);
}

int main() {
    char username[256], newPassword[256];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your new password: ");
    scanf("%s", newPassword);

    updatePassword(username, newPassword);

    return 0;
}