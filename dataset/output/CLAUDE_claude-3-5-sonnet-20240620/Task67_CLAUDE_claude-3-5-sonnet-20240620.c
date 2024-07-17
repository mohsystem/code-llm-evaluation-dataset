
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a customer username.\
");
        return 1;
    }

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[MAX_QUERY_SIZE];
    const char *server = "localhost";
    const char *user = "your_username";
    const char *password = "your_password";
    const char *database = "your_database";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\
", mysql_error(conn));
        return 1;
    }

    snprintf(query, MAX_QUERY_SIZE, "SELECT * FROM customer WHERE customerusername = \'%s\'", argv[1]);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    res = mysql_use_result(conn);

    if ((row = mysql_fetch_row(res)) != NULL) {
        printf("Customer ID: %s\
", row[0]);
        printf("Name: %s\
", row[1]);
        printf("Email: %s\
", row[2]);
        printf("Phone: %s\
", row[3]);
    } else {
        printf("Customer not found.\
");
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
