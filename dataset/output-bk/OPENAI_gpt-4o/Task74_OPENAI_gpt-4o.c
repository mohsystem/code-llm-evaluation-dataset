#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

PGconn* createConnection() {
    PGconn *conn = PQconnectdb("user=myuser password=mypassword dbname=mydatabase hostaddr=127.0.0.1 port=5432");

    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "C: Connection to database failed: %s
", PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    } else {
        printf("C: Connection established successfully.
");
    }
    return conn;
}

int main() {
    PGconn *conn = createConnection();
    PQfinish(conn);
    return 0;
}