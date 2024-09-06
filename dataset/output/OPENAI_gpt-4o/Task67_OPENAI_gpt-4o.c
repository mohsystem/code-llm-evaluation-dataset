#include <stdio.h>
#include <sqlite3.h>

void get_customer_info(const char *username) {
    sqlite3 *db;
    sqlite3_open("your_database.db", &db);
    const char *query = "SELECT * FROM customer WHERE username = ?";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int col = 0; col < sqlite3_column_count(stmt); col++) {
            printf("%s ", sqlite3_column_text(stmt, col));
        }
        printf("\n");
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <customerusername>\n", argv[0]);
        return 1;
    }
    const char *username = argv[1];
    get_customer_info(username);
    return 0;
}