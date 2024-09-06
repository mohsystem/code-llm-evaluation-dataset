
#include <iostream>
#include <pqxx/pqxx>

pqxx::connection* createConnection() {
    try {
        pqxx::connection* conn = new pqxx::connection(
            "host=localhost "
            "dbname=your_database "
            "user=your_username "
            "password=your_password"
        );
        
        if (conn->is_open()) {
            std::cout << "Connection created successfully" << std::endl;
            return conn;
        } else {
            delete conn;
            return nullptr;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error while connecting to PostgreSQL: " << e.what() << std::endl;
        return nullptr;
    }
}

int main() {
    pqxx::connection* conn = createConnection();
    if (conn) {
        conn->disconnect();
        delete conn;
    }
    return 0;
}
