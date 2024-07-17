#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

void hashPassword(char* password, char* hashedPassword) {
    // Simple hashing example, in real-world scenarios use a secure hashing algorithm like bcrypt
    sprintf(hashedPassword, "%d", (int)strlen(password));
}

int main() {
    char username[256];
    char password[256];
    char hashedPassword[256];

    printf("Enter username: ");
    fgets(username, 256, stdin);
    username[strcspn(username, "
")] = 0; // remove newline character

    printf("Enter new password: ");
    fgets(password, 256, stdin);
    password[strcspn(password, "
")] = 0; // remove newline character

    hashPassword(password, hashedPassword);

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "mydb", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s
", mysql_error(conn));
        return 1;
    }

    char query[512];
    sprintf(query, "UPDATE users SET password = '%s' WHERE username = '%s'", hashedPassword, username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error updating password: %s
", mysql_error(conn));
        return 1;
    }

    printf("Password updated successfully!
");

    mysql_close(conn);
    return 0;
}