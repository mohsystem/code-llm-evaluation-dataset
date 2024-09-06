#include <iostream>
#include <sqlite3.h>

using namespace std;

int main() {
    sqlite3* db;
    int rc = sqlite3_open("users.db", &db);
    if (rc) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }

    char* errmsg = nullptr;
    rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "name TEXT NOT NULL,"
                          "email TEXT NOT NULL UNIQUE,"
                          "password TEXT NOT NULL"
                          ")", nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        cerr << "Error creating table: " << errmsg << endl;
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    string name, email, password;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);

    string sql = "INSERT INTO users (name, email, password) VALUES ('" + name + "', '" + email + "', '" + password + "')";
    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        if (strstr(errmsg, "UNIQUE constraint failed") != nullptr) {
            cerr << "Error: Email already exists." << endl;
        } else {
            cerr << "Error inserting data: " << errmsg << endl;
        }
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return 1;
    }

    cout << "Registration successful!" << endl;

    sqlite3_close(db);
    return 0;
}