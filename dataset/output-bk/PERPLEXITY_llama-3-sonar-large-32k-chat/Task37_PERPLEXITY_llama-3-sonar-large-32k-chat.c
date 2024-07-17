#include <mysql.h>
#include <stdio.h>
#include <string.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[256];

    char username[256];
    printf("Enter username: ");
    fgets(username, 256, stdin);
    username[strcspn(username, "
")] = 0; // remove newline character

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "mydb", 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    sprintf(query, "SELECT * FROM users WHERE username = '%s'", username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    res = mysql_use_result(conn);
    while ((row = mysql_fetch_row(res))) {
        printf("Username: %s
", row[0]);
        printf("Email: %s
", row[1]);
        printf("Password: %s
", row[2]);
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}