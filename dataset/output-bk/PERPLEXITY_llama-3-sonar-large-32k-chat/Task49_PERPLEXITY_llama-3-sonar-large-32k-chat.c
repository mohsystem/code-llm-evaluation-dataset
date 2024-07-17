#include <mysql.h>
#include <stdio.h>
#include <string.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "mydb";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    char query[256];
    sprintf(query, "CREATE TABLE IF NOT EXISTS users (name VARCHAR(255), email VARCHAR(255))");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    printf("Enter name: ");
    char name[256];
    fgets(name, 256, stdin);
    name[strcspn(name, "
")] = 0; // remove newline character

    printf("Enter email: ");
    char email[256];
    fgets(email, 256, stdin);
    email[strcspn(email, "
")] = 0; // remove newline character

    sprintf(query, "INSERT INTO users (name, email) VALUES ('%s', '%s')", name, email);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
        return 1;
    }

    mysql_close(conn);
    return 0;
}