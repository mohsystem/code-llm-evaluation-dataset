#include <libpq-fe.h>
#include <iostream>

PGconn* createConnection() {
    PGconn* conn = PQconnectdb(
        "host=localhost port=5432 dbname=database_name user=username password=password"
    );
    if (PQstatus(conn) == CONNECTION_OK) {
        return conn;
    } else {
        std::cout << "Error connecting to database: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return nullptr;
    }
}

int main() {
    PGconn* conn = createConnection();
    if (conn != nullptr) {
        PQfinish(conn);
    }
    return 0;
}