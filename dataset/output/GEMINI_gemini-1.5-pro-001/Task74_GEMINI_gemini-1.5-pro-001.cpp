#include <iostream>
#include <pqxx/pqxx> 

pqxx::connection* connect_to_postgres(const std::string& host, const std::string& database, 
                                        const std::string& user, const std::string& password) {
    try {
        std::string conn_string = "host=" + host + " dbname=" + database + " user=" + user + " password=" + password;
        return new pqxx::connection(conn_string);
    } catch (const std::exception &e) {
        std::cerr << "Error connecting to database: " << e.what() << std::endl;
        return nullptr;
    }
}