
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

PGconn* getConnection() {
    const char* conninfo = "host=localhost port=5432 dbname=your_database user=your_username password=your_password";
    PGconn* conn = PQconnectdb(conninfo);
    
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }
    
    return conn;
}

int main() {
    PGconn* conn = getConnection();
    if (conn != NULL) {
        printf("Connected to the database!\
");
        PQfinish(conn);
    } else {
        printf("Failed to connect to the database.\
");
    }
    return 0;
}
