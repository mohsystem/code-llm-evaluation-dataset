#include <iostream>
#include <sqlite3.h>

using namespace std;

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("your_database.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }

    string username;
    cout << "Enter username: ";
    cin >> username;

    string sql = "SELECT * FROM users WHERE username='" + username + "'";
    const char* query = sql.c_str();

    rc = sqlite3_exec(db, query, [](void *data, int argc, char **argv, char **azColName) -> int {
        for (int i = 0; i < argc; i++) {
            cout << azColName[i] << ": " << argv[i] ? argv[i] : "NULL" << endl;
        }
        cout << endl;
        return 0;
    }, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } 

    sqlite3_close(db);
    return 0;
}