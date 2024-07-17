// C
#include <mysql.h>
#include <stdio.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "username";
    char *password = "password";
    char *database = "myDatabase";

    char username[50];
    printf("Enter username: ");
    scanf("%s", username);

    char query[100] = "SELECT * FROM Users WHERE username = '";
    strcat(query, username);
    strcat(query, "'");

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    res = mysql_use_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%s %s
", row[0], row[1]);

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}