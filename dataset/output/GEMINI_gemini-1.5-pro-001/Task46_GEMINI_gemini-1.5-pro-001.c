#include <stdio.h>
#include <string.h>
#include <mysql.h>

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Error: %s
", mysql_error(conn));
        return 1;
    }

    if (mysql_real_connect(conn, "localhost", "username", "password", "user_db", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    char name[100], email[100], password[100];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "
")] = 0; // remove trailing newline

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "
")] = 0;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "
")] = 0;

    char query[255];
    sprintf(query, "INSERT INTO users (name, email, password) VALUES ('%s', '%s', '%s')", name, email, password);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    } else {
        printf("Registration successful!
");
    }

    mysql_close(conn);
    return 0;
}