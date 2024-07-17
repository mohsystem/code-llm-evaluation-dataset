
#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

connection* getConnection() {
    try {
        return new connection("host=localhost port=5432 dbname=your_database user=your_username password=your_password");
    } catch (const exception &e) {
        cerr << e.what() << endl;
        return nullptr;
    }
}

int main() {
    connection* conn = getConnection();
    if (conn != nullptr) {
        cout << "Connected to the database!" << endl;
        delete conn;
    } else {
        cout << "Failed to connect to the database." << endl;
    }
    return 0;
}
