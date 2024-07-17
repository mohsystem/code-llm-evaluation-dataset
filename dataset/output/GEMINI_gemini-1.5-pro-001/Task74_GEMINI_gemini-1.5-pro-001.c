#include <stdio.h>
#include <libpq-fe.h>

PGconn* connectToDatabase(const char* conninfo) {
    PGconn* conn = PQconnectdb(conninfo);

    if (PQstatus(conn) == CONNECTION_OK) {
        return conn;
    } else {
        fprintf(stderr, "Connection to database failed: %s
", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }
}

int main() {
    const char* conninfo = "host=localhost port=5432 dbname=your_database_name user=your_username password=your_password";

    PGconn* conn = connectToDatabase(conninfo);

    if (conn != NULL) {
        PQfinish(conn);
        return 0;
    } else {
        return 1;
    }
}