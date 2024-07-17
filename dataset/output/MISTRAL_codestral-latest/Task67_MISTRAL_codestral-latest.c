// C
#include <mysql.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "username";
    char *password = "password";
    char *database = "myDatabase";

    char query[200];
    sprintf(query, "SELECT * FROM customer WHERE username = '%s'", argv[1]);

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

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s %s %s
", row[0], row[1], row[2]);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}