#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <mysql/mysql.h>

void hashPassword(char *password, char *hashedPassword) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashedPassword[i * 2], "%02x", hash[i]);
    }
}

int main() {
    char username[255];
    char newPassword[255];
    char hashedPassword[SHA256_DIGEST_LENGTH * 2 + 1];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", newPassword);

    hashPassword(newPassword, hashedPassword);

    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "%s
", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "your_database_user", "your_database_password", "your_database_name", 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s
", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    char query[512];
    sprintf(query, "UPDATE users SET password = '%s' WHERE username = '%s'", hashedPassword, username);

    if (mysql_query(con, query)) {
        fprintf(stderr, "%s
", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    printf("Password updated successfully.
");

    mysql_close(con);
    return 0;
}