#include <mysql.h>
#include <stdio.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char name[50], email[50], password[50];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter email: ");
    scanf("%s", email);

    printf("Enter password: ");
    scanf("%s", password);

    char query[200];
    sprintf(query, "INSERT INTO users (name, email, password) VALUES ('%s', '%s', '%s')", name, email, password);

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "mydb", 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    mysql_close(conn);

    return 0;
}