#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    char username[50];
    printf("Enter username: ");
    scanf("%s", username);

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "yourusername";
    char *password = "yourpassword"; 
    char *database = "yourdatabasename";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    char query[256];
    sprintf(query, "SELECT * FROM users WHERE username = '%s'", username);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("Username: %s
", row[0]);
        printf("Email: %s
", row[1]);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}