
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_USERNAME_LENGTH 50

void get_user_info(const char* username) {
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Error: %s\\n", mysql_error(conn));
        return;
    }

    if (mysql_real_connect(conn, "localhost", "your_username", "your_password", "your_database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error: %s\\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    char query[100 + MAX_USERNAME_LENGTH];
    snprintf(query, sizeof(query), "SELECT * FROM users WHERE username = '%s'", username);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    res = mysql_use_result(conn);
    if ((row = mysql_fetch_row(res)) != NULL) {
        printf("User found: %s\\n", row[0]);
    } else {
        printf("User not found\\n");
    }

    mysql_free_result(res);
    mysql_close(conn);
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\\n")] = 0;  // Remove newline

    get_user_info(username);
    return 0;
}
