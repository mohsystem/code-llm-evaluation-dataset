#include <stdio.h>
#include <mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char username[50];
    char query[200];

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database_name", 3306, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s
", mysql_error(conn));
        return 1;
    }

    printf("Enter username: ");
    scanf("%s", username);

    sprintf(query, "SELECT * FROM users WHERE username = '%s'", username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    result = mysql_store_result(conn);
    if (!result) {
        fprintf(stderr, "Error storing result: %s
", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    while ((row = mysql_fetch_row(result))) {
        printf("Username: %s
", row[0]);
        printf("Email: %s
", row[1]);
        // Retrieve other user information as needed
    }

    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}