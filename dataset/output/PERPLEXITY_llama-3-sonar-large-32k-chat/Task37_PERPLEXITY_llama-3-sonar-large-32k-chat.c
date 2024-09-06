// Note: This code uses the mysql-connector-c library, which is not a standard C library.
// You need to install it and link it to your project.

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

int main() {
    char username[256];
    printf("Enter username: ");
    scanf("%255s", username);
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0)) {
        printf("Error connecting to database\n");
        return 1;
    }
    char query[256];
    sprintf(query, "SELECT * FROM users WHERE username = '%s'", username);
    if (mysql_query(conn, query)) {
        printf("Error executing query\n");
        return 1;
    }
    res = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res)) != NULL) {
        printf("User found: %s, %s\n", row[0], row[1]);
    } else {
        printf("User not found\n");
    }
    mysql_close(conn);
    return 0;
}