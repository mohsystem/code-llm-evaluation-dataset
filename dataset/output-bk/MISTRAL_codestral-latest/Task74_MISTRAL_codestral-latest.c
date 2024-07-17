// C
#include <libpq-fe.h>
#include <stdio.h>

PGconn* getConnection() {
    const char *conninfo = "host=localhost dbname=test user=postgres password=password";
    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }

    return conn;
}