// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <openssl/sha.h>

void hashPassword(const char *password, char *hashedPassword) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashedPassword + (i * 2), "%02x", hash[i]);
    }
    hashedPassword[64] = 0;
}

void updatePasswordInDatabase(MYSQL *conn, const char *username, const char *hashedPassword) {
    char query[256];
    sprintf(query, "UPDATE users SET password = '%s' WHERE username = '%s'", hashedPassword, username);
    mysql_query(conn, query);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "mydatabase", 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    char username[256], password[256], hashedPassword[65];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter new password: ");
    scanf("%s", password);

    hashPassword(password, hashedPassword);

    updatePasswordInDatabase(conn, username, hashedPassword);

    mysql_close(conn);
    return 0;
}