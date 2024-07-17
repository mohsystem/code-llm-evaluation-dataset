#include <iostream>
#include <pqxx/pqxx>

pqxx::connection* connectToDatabase(const std::string& connectionString) {
    try {
        return new pqxx::connection(connectionString);
    } catch (const std::exception& e) {
        std::cerr << "Connection failed: " << e.what() << std::endl;
        return nullptr;
    }
}

int main() {
    const std::string connectionString = "host=localhost port=5432 dbname=your_database_name user=your_username password=your_password";

    pqxx::connection* connection = connectToDatabase(connectionString);

    if (connection && connection->is_open()) {
        std::cout << "Connected to database successfully!" << std::endl;
        delete connection;
        return 0;
    } else {
        std::cerr << "Connection failed!" << std::endl;
        return 1;
    }
}