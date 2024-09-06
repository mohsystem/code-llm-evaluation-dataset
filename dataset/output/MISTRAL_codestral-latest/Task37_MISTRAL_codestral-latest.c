// C code using libmysqlclient
#include <mysql.h>
#include <stdio.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "username";
    char *password = "password";
    char *database = "my_database";

    char username[50];

    // Connect to the database
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Get username from user
    printf("Enter username: ");
    scanf("%s", username);

    // Execute the query
    char query[100];
    sprintf(query, "SELECT * FROM users WHERE username = '%s'", username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Fetch the results
    res = mysql_use_result(conn);

    // Print the results
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s %s %s\n", row[0], row[1], row[2]);
    }

    // Close the connection
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}