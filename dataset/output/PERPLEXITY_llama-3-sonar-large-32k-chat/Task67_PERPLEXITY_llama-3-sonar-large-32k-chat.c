#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[256];
    char name[256];
    char email[256];
} Customer;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <customerusername>
", argv[0]);
        return 1;
    }
    char *customerUsername = argv[1];
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[1024];

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "mydb", 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    sprintf(query, "SELECT * FROM customer WHERE username = '%s'", customerUsername);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    res = mysql_use_result(conn);
    if ((row = mysql_fetch_row(res))) {
        Customer customer;
        strcpy(customer.username, row[0]);
        strcpy(customer.name, row[1]);
        strcpy(customer.email, row[2]);
        printf("Customer: username=%s, name=%s, email=%s
", customer.username, customer.name, customer.email);
    } else {
        printf("Customer not found
");
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}