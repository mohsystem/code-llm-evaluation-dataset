#include <stdio.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "testdb";

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    char name[100], email[100], password_in[100];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter password: ");
    scanf("%s", password_in);

    char query[256];
    sprintf(query, "INSERT INTO users (name, email, password) VALUES ('%s', '%s', '%s')", name, email, password_in);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        exit(1);
    }

    printf("User registered successfully!
");
    mysql_close(conn);
    return 0;
}