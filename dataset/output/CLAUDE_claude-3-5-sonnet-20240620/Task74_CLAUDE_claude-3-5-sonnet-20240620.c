
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

PGconn* createConnection() {
    const char *conninfo = "host=localhost dbname=your_database user=your_username password=your_password";
    
    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) == CONNECTION_OK) {
        printf("Connection created successfully\\n");
        return conn;
    } else {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }
}

int main() {
    PGconn *conn = createConnection();
    if (conn) {
        PQfinish(conn);
    }
    return 0;
}
