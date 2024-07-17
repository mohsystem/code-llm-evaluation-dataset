#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "mongoose.h"

#define DATABASE "users.db"

// Structure to hold user data
typedef struct {
    char name[100];
    char email[100];
} User;

// Callback function for SQLite queries
static int callback(void* data, int argc, char** argv, char** azColName) {
    return 0;
}

// Function to handle user creation API endpoint
static void create_user_handler(struct mg_connection* conn, int ev, void* ev_data) {
    if (ev != MG_EV_HTTP_REQUEST) {
        return;
    }

    struct http_message* hm = (struct http_message*)ev_data;
    if (mg_vcmp(&hm->method, "POST") != 0) {
        mg_http_reply(conn, 405, "text/plain", "Method Not Allowed
");
        return;
    }

    // Connect to the SQLite database
    sqlite3* db;
    int rc = sqlite3_open(DATABASE, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s
", sqlite3_errmsg(db));
        mg_http_reply(conn, 500, "text/plain", "Internal Server Error
");
        return;
    }

    // Create the users table if it doesn't exist
    char* err_msg = 0;
    char* sql = "CREATE TABLE IF NOT EXISTS users ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL,"
                "email TEXT NOT NULL UNIQUE"
                ");";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s
", err_msg);
        sqlite3_free(err_msg);
        mg_http_reply(conn, 500, "text/plain", "Internal Server Error
");
        sqlite3_close(db);
        return;
    }

    // Parse the user data from the request body
    User user;
    mg_get_http_var(&hm->body, "name", user.name, sizeof(user.name));
    mg_get_http_var(&hm->body, "email", user.email, sizeof(user.email));

    // Check if name and email are provided
    if (strlen(user.name) == 0 || strlen(user.email) == 0) {
        mg_http_reply(conn, 400, "text/plain", "Name and email are required
");
        sqlite3_close(db);
        return;
    }

    // Insert the user data into the database
    sql = sqlite3_mprintf("INSERT INTO users(name, email) VALUES('%q', '%q')", user.name, user.email);
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    sqlite3_free(sql); // Free the SQL statement

    if (rc != SQLITE_OK) {
        if (err_msg != NULL && strstr(err_msg, "UNIQUE constraint failed") != NULL) {
            mg_http_reply(conn, 400, "text/plain", "Email address already exists
");
        } else {
            fprintf(stderr, "SQL error: %s
", err_msg);
            mg_http_reply(conn, 500, "text/plain", "Internal Server Error
");
        }
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }

    // Send a success response
    mg_http_reply(conn, 201, "text/plain", "User created successfully
");

    // Close the database connection
    sqlite3_close(db);
}

int main(void) {
    struct mg_mgr mgr;
    mg_mgr_init(&mgr, NULL);

    mg_connection* conn = mg_bind(&mgr, "8080", create_user_handler);
    if (conn == NULL) {
        fprintf(stderr, "Error starting server on port 8080
");
        exit(1);
    }

    mg_set_protocol_http_websocket(conn);

    printf("Starting server on port 8080
");
    for (;;) {
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);

    return 0;
}