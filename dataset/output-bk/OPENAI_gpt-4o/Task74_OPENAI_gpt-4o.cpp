#include <iostream>
#include <pqxx/pqxx>

pqxx::connection* createConnection() {
    pqxx::connection* conn = nullptr;
    try {
        conn = new pqxx::connection("dbname=mydatabase user=myuser password=mypassword hostaddr=127.0.0.1 port=5432");
        if (conn->is_open()) {
            std::cout << "C++: Connection established successfully." << std::endl;
        } else {
            std::cout << "C++: Connection failed." << std::endl;
            delete conn;
            conn = nullptr;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return conn;
}

int main() {
    pqxx::connection* conn = createConnection();
    if (conn) {
        delete conn;
    }
    return 0;
}