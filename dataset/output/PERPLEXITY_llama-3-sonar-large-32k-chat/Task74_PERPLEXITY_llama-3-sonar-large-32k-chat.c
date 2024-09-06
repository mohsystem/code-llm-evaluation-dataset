#include <libpq-fe.h>
#include <stdio.h>

PGconn* createConnection() {
    PGconn* conn = PQconnectdb(
        "host=localhost port=5432 dbname=database_name user=username password=password"
    );
    if (PQstatus(conn) == CONNECTION_OK) {
        return conn;
    } else {
        fprintf(stderr, "Error connecting to database: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }
}

int main() {
    PGconn* conn = createConnection();
    if (conn != NULL) {
        PQfinish(conn);
    }
    return 0;
}