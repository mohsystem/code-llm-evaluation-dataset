#include <stdio.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <customer_username>\n", argv[0]);
        return 1;
    }
    char username[256];
    strcpy(username, argv[1]);
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0)) {
        printf("Error: %s\n", mysql_error(conn));
        return 1;
    }
    char query[256];
    sprintf(query, "SELECT * FROM customer WHERE customerusername = '%s'", username);
    if (mysql_query(conn, query)) {
        printf("Error: %s\n", mysql_error(conn));
        return 1;
    }
    res = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res))) {
        printf("%s %s ...\n", row[0], row[1]);
    } else {
        printf("Customer not found\n");
    }
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}