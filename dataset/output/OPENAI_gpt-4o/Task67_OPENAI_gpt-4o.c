#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <customerusername>
", argv[0]);
        return 1;
    }
    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "yourdb";
    char *username = argv[1];
    
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    char query[256];
    snprintf(query, 256, "SELECT * FROM customer WHERE username='%s'", username);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res))) {
        printf("ID: %s
", row[0]);
        printf("Username: %s
", row[1]);
        printf("Name: %s
", row[2]);
        printf("Email: %s
", row[3]);
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}