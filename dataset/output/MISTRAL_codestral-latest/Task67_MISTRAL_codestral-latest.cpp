#include <iostream>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <customerusername>" << std::endl;
        return 1;
    }

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char *data = "Callback function called";

    rc = sqlite3_open("database.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    sql = "SELECT * FROM customer WHERE customerusername = ?";

    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    rc = sqlite3_bind_text(stmt, 1, argv[1], -1, SQLITE_TRANSIENT);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL bind error: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    rc = sqlite3_exec(db, "BEGIN", NULL, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return rc;
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        callback(data, sqlite3_column_count(stmt), sqlite3_column_text(stmt, 0), sqlite3_column_name(stmt, 0));
    } else if (rc == SQLITE_DONE) {
        std::cout << "No customer found with username: " << argv[1] << std::endl;
    } else {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}