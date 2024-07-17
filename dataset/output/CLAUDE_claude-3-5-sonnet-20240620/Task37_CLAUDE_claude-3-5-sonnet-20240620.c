
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_USERNAME_LENGTH 50

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char username[MAX_USERNAME_LENGTH];
    char query[100];

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\
");
        return 1;
    }

    if (mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\
");
        mysql_close(conn);
        return 1;
    }

    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\
")] = 0;

    snprintf(query, sizeof(query), "SELECT * FROM users WHERE username = \'%s\'", username);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "mysql_query() failed\
");
        mysql_close(conn);
        return 1;
    }

    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed\
");
        mysql_close(conn);
        return 1;
    }

    if ((row = mysql_fetch_row(res)) != NULL) {
        printf("User ID: %s\
", row[0]);
        printf("Username: %s\
", row[1]);
        printf("Email: %s\
", row[2]);
    } else {
        printf("User not found.\
");
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
