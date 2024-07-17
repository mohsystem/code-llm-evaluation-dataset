
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <mysql/mysql.h>

#define MAX_LENGTH 100

void hash_password(const char* password, char* hashed_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashed_password[i * 2], "%02x", hash[i]);
    }
    hashed_password[SHA256_DIGEST_LENGTH * 2] = \'\\0\';
}

void update_password_in_database(const char* username, const char* hashed_password) {
    MYSQL* conn;
    MYSQL_STMT* stmt;
    MYSQL_BIND bind[2];
    
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\
");
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\
");
        mysql_close(conn);
        exit(1);
    }

    const char* sql = "UPDATE users SET password = ? WHERE username = ?";
    stmt = mysql_stmt_init(conn);
    if (stmt == NULL) {
        fprintf(stderr, "mysql_stmt_init() failed\
");
        mysql_close(conn);
        exit(1);
    }

    if (mysql_stmt_prepare(stmt, sql, strlen(sql)) != 0) {
        fprintf(stderr, "mysql_stmt_prepare() failed\
");
        mysql_stmt_close(stmt);
        mysql_close(conn);
        exit(1);
    }

    memset(bind, 0, sizeof(bind));

    bind[0].buffer_type = MYSQL_TYPE_STRING;
    bind[0].buffer = (char*)hashed_password;
    bind[0].buffer_length = strlen(hashed_password);

    bind[1].buffer_type = MYSQL_TYPE_STRING;
    bind[1].buffer = (char*)username;
    bind[1].buffer_length = strlen(username);

    if (mysql_stmt_bind_param(stmt, bind) != 0) {
        fprintf(stderr, "mysql_stmt_bind_param() failed\
");
        mysql_stmt_close(stmt);
        mysql_close(conn);
        exit(1);
    }

    if (mysql_stmt_execute(stmt) != 0) {
        fprintf(stderr, "mysql_stmt_execute() failed\
");
        mysql_stmt_close(stmt);
        mysql_close(conn);
        exit(1);
    }

    if (mysql_stmt_affected_rows(stmt) > 0) {
        printf("Password updated successfully.\
");
    } else {
        printf("User not found.\
");
    }

    mysql_stmt_close(stmt);
    mysql_close(conn);
}

int main() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char hashed_password[SHA256_DIGEST_LENGTH * 2 + 1];

    printf("Enter username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\
")] = \'\\0\';

    printf("Enter new password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\
")] = \'\\0\';

    hash_password(password, hashed_password);
    update_password_in_database(username, hashed_password);

    return 0;
}
