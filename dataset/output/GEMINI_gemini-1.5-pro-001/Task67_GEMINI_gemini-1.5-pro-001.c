//This is not possible as one file in c as we need to use sqlite3 library which require to be in seperate files
//and compiled with main file, so this example only provide the c code for interacting with database
//assuming a sqlite3 library is available
#include <stdio.h>
#include <sqlite3.h>

typedef struct Customer {
    char customerusername[255];
    char customerfirstname[255];
    // Add other fields as needed
} Customer;

Customer get_customer_info(const char* customerusername) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    Customer customer = {0}; // Initialize the struct

    rc = sqlite3_open("your_database.db", &db); // Replace 'your_database.db'
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return customer;
    }

    char sql[255] = "SELECT * FROM customer WHERE customerusername = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return customer;
    }

    sqlite3_bind_text(stmt, 1, customerusername, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        strcpy(customer.customerusername, (const char*)sqlite3_column_text(stmt, 0));
        strcpy(customer.customerfirstname, (const char*)sqlite3_column_text(stmt, 1));
        // Fetch other fields
    } 

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return customer;
}