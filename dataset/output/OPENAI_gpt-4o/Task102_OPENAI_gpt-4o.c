// C code to accept username and password, hash the password, and update the database
// Comment: Complete SQLite interaction in C can be complex and beyond the scope of this template.

#include <stdio.h>
#include <openssl/sha.h>
#include <sqlite3.h>

void hashPassword(const char* password, char* outputBuffer) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int updatePassword(const char* username, const char* password) {
    sqlite3* db;
    char* errMsg = 0;
    int rc;
    
    rc = sqlite3_open("users.db", &db);
    if (rc != SQLITE_OK) {
        return rc;
    }
    
    char hashedPassword[65];
    hashPassword(password, hashedPassword);
    
    char sql[256];
    sprintf(sql, "CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT);");
    sqlite3_exec(db, sql, 0, 0, &errMsg);

    sprintf(sql, "UPDATE users SET password = '%s' WHERE username = '%s';", hashedPassword, username);
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    
    sqlite3_close(db);
    return rc;
}

int main(void) {
    char username[50];
    char password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);
    
    int result = updatePassword(username, password);
    if(result == SQLITE_OK) {
        printf("Password updated successfully!\n");
    } else {
        printf("Failed to update password.\n");
    }
    return 0;
}