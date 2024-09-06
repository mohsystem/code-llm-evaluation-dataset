#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <sqlite3.h>

void hash_password(const char* password, char* output) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
}

int update_password(const char* username, const char* new_password) {
    char hashed_password[SHA256_DIGEST_LENGTH * 2 + 1];
    hash_password(new_password, hashed_password);

    sqlite3* db;
    char* err_msg = 0;
    int rc = sqlite3_open("users.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    char sql[256];
    sprintf(sql, "UPDATE user SET password = '%s' WHERE username = '%s';", hashed_password, username);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    sqlite3_close(db);
    printf("Password updated successfully!\n");
    return 0;
}

int main() {
    char username[100], new_password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", new_password);
    update_password(username, new_password);
    return 0;
}