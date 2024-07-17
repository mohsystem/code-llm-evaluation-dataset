#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <customerusername>
", argv[0]);
        return 1;
    }

    const char *customerUsername = argv[1];
    const char *dbHost = "localhost";
    const char *dbUser = "your_username";
    const char *dbPass = "your_password";
    const char *dbName = "your_database_name";

    MYSQL *conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "mysql_init() failed
");
        return 1;
    }

    if (!mysql_real_connect(conn, dbHost, dbUser, dbPass, dbName, 0, NULL, 0)) {
        fprintf(stderr, "mysql_real_connect() failed: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    char query[255];
    sprintf(query, "SELECT * FROM customer WHERE customerusername='%s'", customerUsername);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "mysql_query() failed: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (!result) {
        fprintf(stderr, "mysql_store_result() failed: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row) {
        // Assuming customer table has columns: customerusername, firstname, lastname, email
        printf("Customer Information:
");
        for (int i = 0; i < num_fields; i++) {
            printf("%s: %s
", mysql_fetch_field_direct(result, i)->name, row[i]);
        }
    } else {
        printf("Customer not found.
");
    }

    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}