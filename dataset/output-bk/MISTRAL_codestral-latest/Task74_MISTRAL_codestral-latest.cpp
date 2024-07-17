// C++
#include <libpq-fe.h>
#include <iostream>

PGconn* getConnection() {
    const char *conninfo = "host=localhost dbname=test user=postgres password=password";
    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return NULL;
    }

    return conn;
}