
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct {
    int id;
    char username[50];
    char name[100];
    char email[100];
    char phone[20];
} CustomerInfo;

CustomerInfo* getCustomerInfo(const char* username) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    CustomerInfo* customer = NULL;

    if (sqlite3_open("customer_database.db", &db) == SQLITE_OK) {
        const char* sql = "SELECT * FROM customer WHERE customerusername = ?";
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);

            if (sqlite3_step(stmt) == SQLITE_ROW) {
                customer = (CustomerInfo*)malloc(sizeof(CustomerInfo));
                customer->id = sqlite3_column_int(stmt, 0);
                strncpy(customer->username, (const char*)sqlite3_column_text(stmt, 1), sizeof(customer->username) - 1);
                strncpy(customer->name, (const char*)sqlite3_column_text(stmt, 2), sizeof(customer->name) - 1);
                strncpy(customer->email, (const char*)sqlite3_column_text(stmt, 3), sizeof(customer->email) - 1);
                strncpy(customer->phone, (const char*)sqlite3_column_text(stmt, 4), sizeof(customer->phone) - 1);
            }

            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }

    return customer;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <customerusername>\\n", argv[0]);
        return 1;
    }

    const char* username = argv[1];
    CustomerInfo* customerInfo = getCustomerInfo(username);

    if (customerInfo) {
        printf("Customer Information:\\n");
        printf("ID: %d\\n", customerInfo->id);
        printf("Username: %s\\n", customerInfo->username);
        printf("Name: %s\\n", customerInfo->name);
        printf("Email: %s\\n", customerInfo->email);
        printf("Phone: %s\\n", customerInfo->phone);
        free(customerInfo);
    } else {
        printf("Customer not found.\\n");
    }

    return 0;
}
