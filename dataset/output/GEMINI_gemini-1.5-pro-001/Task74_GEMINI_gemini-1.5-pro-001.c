/* This code requires libpq, the PostgreSQL C client library.
   Install it on your system using the package manager and 
   link it during compilation. Example for GCC:
   gcc your_program.c -lpq -o your_program
*/

#include <stdio.h>
#include <libpq-fe.h>

PGconn* connect_to_postgres(const char *host, const char *database, 
                          const char *user, const char *password) {
    PGconn *conn = NULL;

    conn = PQsetdbLogin(host, NULL, NULL, NULL, database, user, password);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }

    return conn;
}