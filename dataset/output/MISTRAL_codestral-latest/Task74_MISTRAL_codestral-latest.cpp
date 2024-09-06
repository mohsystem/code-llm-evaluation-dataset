// CPP
#include <iostream>
#include <pqxx/pqxx>

pqxx::connection createDBConnection() {
    try {
        pqxx::connection conn("dbname = your_database user = your_username password = your_password hostaddr = 127.0.0.1 port = 5432");
        if (conn.is_open()) {
            std::cout << "Connected to " << conn.dbname() << std::endl;
        } else {
            std::cout << "Can't open database" << std::endl;
        }
        return conn;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return pqxx::connection();
    }
}

int main(int argc, char* argv[]) {
    pqxx::connection conn = createDBConnection();
    return 0;
}