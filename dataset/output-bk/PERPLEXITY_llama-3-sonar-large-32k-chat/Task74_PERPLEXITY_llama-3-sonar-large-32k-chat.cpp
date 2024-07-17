#include <libpq-fe.h>
#include <iostream>

int main() {
    PGconn *conn = PQconnectdb("host=localhost port=5432 dbname=mydb user=username password=password");
    if (PQstatus(conn) == CONNECTION_OK) {
        std::cout << "Connected to the database." << std::endl;
    } else {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
    }
    PQfinish(conn);
    return 0;
}