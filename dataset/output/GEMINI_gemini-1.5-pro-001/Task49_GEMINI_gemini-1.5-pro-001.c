#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <microhttpd.h>

#define PORT 8080

// Callback function for handling HTTP requests
static int handle_request(void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
    if (strcmp(method, "POST") == 0 && strcmp(url, "/users") == 0) {
        // Get the POST data
        const char *name = NULL, *email = NULL;
        char *data = (char *) upload_data;

        // Parse the POST data (assuming application/x-www-form-urlencoded)
        // Note: This is a simple parsing example and might need adjustments
        // depending on the actual data format.
        while (*data) {
            char *key = data;
            char *value = strchr(key, '=');
            if (value) {
                *value++ = '\0';
                if (strcmp(key, "name") == 0) {
                    name = value;
                } else if (strcmp(key, "email") == 0) {
                    email = value;
                }
                data = strchr(value, '&');
                if (data) {
                    *data++ = '\0';
                } else {
                    break; // End of data
                }
            }
        }

        if (name && email) {
            // Open database connection
            sqlite3 *db;
            char *zErrMsg = 0;
            int rc = sqlite3_open("users.db", &db);
            if (rc) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return MHD_NO;
            }

            // Create a table for users if it doesn't exist
            char *sqlCreateTable = "CREATE TABLE IF NOT EXISTS users ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                   "name TEXT NOT NULL,"
                                   "email TEXT NOT NULL UNIQUE"
                                   ");";
            rc = sqlite3_exec(db, sqlCreateTable, 0, 0, &zErrMsg);
            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                sqlite3_close(db);
                return MHD_NO;
            }

            // Insert user data into the database
            char sqlInsert[256];
            sprintf(sqlInsert, "INSERT INTO users (name, email) VALUES ('%s', '%s')", name, email);
            rc = sqlite3_exec(db, sqlInsert, 0, 0, &zErrMsg);
            if (rc != SQLITE_OK) {
                if (strstr(zErrMsg, "UNIQUE constraint failed") != NULL) {
                    // Email already exists
                    sqlite3_free(zErrMsg);
                    sqlite3_close(db);

                    // Return 400 Bad Request
                    struct MHD_Response *response =
                            MHD_create_response_from_buffer(strlen("Email already exists"),
                                                           "Email already exists",
                                                           MHD_RESPMEM_MUST_COPY);
                    MHD_add_response_header(response, "Content-Type", "text/plain");
                    int ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
                    MHD_destroy_response(response);
                    return ret;
                } else {
                    fprintf(stderr, "SQL error: %s\n", zErrMsg);
                    sqlite3_free(zErrMsg);
                    sqlite3_close(db);
                    return MHD_NO;
                }
            }

            // Close database connection
            sqlite3_close(db);

            // Return 201 Created
            struct MHD_Response *response =
                    MHD_create_response_from_buffer(strlen("User created successfully"),
                                                   "User created successfully",
                                                   MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "text/plain");
            int ret = MHD_queue_response(connection, MHD_HTTP_CREATED, response);
            MHD_destroy_response(response);
            return ret;
        } else {
            // Missing name or email
            // Return 400 Bad Request
            struct MHD_Response *response =
                    MHD_create_response_from_buffer(strlen("Name and email are required"),
                                                   "Name and email are required",
                                                   MHD_RESPMEM_MUST_COPY);
            MHD_add_response_header(response, "Content-Type", "text/plain");
            int ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
            MHD_destroy_response(response);
            return ret;
        }
    }

    return MHD_NO; // Not handled
}

int main(void) {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);
    if (NULL == daemon) {
        fprintf(stderr, "Failed to start HTTP server.\n");
        return 1;
    }

    printf("Server running on port %d...\n", PORT);
    getchar(); // Wait for user input before stopping the server

    MHD_stop_daemon(daemon);
    return 0;
}