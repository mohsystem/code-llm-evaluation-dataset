#include <libpq-fe.h>

int main() {
    PGconn *conn = PQconnectdb("host=localhost port=5432 dbname=mydb user=username password=password");
    if (PQstatus(conn) == CONNECTION_OK) {
        printf("Connected to the database.
");
    } else {
        printf("Connection to database failed: %s
", PQerrorMessage(conn));
    }
    PQfinish(conn);
    return 0;
}