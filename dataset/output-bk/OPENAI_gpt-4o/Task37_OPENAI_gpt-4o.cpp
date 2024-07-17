#include <iostream>
#include <mysql/mysql.h>
using namespace std;

int main() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "localhost";
    const char *user = "yourusername";
    const char *password = "yourpassword";
    const char *database = "yourdatabasename";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        cerr << mysql_error(conn) << endl;
        exit(1);
    }

    string query = "SELECT * FROM users WHERE username = '" + username + "'";
    if (mysql_query(conn, query.c_str())) {
        cerr << mysql_error(conn) << endl;
        exit(1);
    }

    res = mysql_store_result(conn);

    while ((row = mysql_fetch_row(res)) != NULL) {
        cout << "Username: " << row[0] << endl;
        cout << "Email: " << row[1] << endl;
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}