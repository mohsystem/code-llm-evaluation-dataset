
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>
#include <sqlite3.h>

#define PORT 8080

static int handle_request(void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
    if (strcmp(method, "POST") != 0) {
        const char *page = "Method not allowed";
        return MHD_queue_response(connection, MHD_HTTP_METHOD_NOT_ALLOWED,
                                  MHD_create_response_from_buffer(strlen(page), (void*)page, MHD_RESPMEM_PERSISTENT));
    }

    if (*con_cls == NULL) {
        *con_cls = malloc(1);
        return MHD_YES;
    }

    if (*upload_data_size != 0) {
        char *name = NULL;
        char *email = NULL;
        char *saveptr;
        char *token = strtok_r((char *)upload_data, "&", &saveptr);
        while (token != NULL) {
            if (strncmp(token, "name=", 5) == 0) {
                name = token + 5;
            } else if (strncmp(token, "email=", 6) == 0) {
                email = token + 6;
            }
            token = strtok_r(NULL, "&", &saveptr);
        }

        if (name && email) {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open("users.db", &db);
            if (rc != SQLITE_OK) {
                fprintf(stderr, "Cannot open database: %s\\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return MHD_NO;
            }

            char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT);"
                        "INSERT INTO users (name, email) VALUES (?, ?);";

            sqlite3_stmt *stmt;
            rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
            if (rc != SQLITE_OK) {
                fprintf(stderr, "Failed to prepare statement: %s\\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return MHD_NO;
            }

            sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, email, -1, SQLITE_STATIC);

            rc = sqlite3_step(stmt);
            if (rc != SQLITE_DONE) {
                fprintf(stderr, "Execution failed: %s\\n", sqlite3_errmsg(db));
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return MHD_NO;
            }

            sqlite3_finalize(stmt);
            sqlite3_close(db);
        }

        *upload_data_size = 0;
        return MHD_YES;
    }

    const char *page = "User created successfully";
    struct MHD_Response *response = MHD_create_response_from_buffer(strlen(page), (void*)page, MHD_RESPMEM_PERSISTENT);
    int ret = MHD_queue_response(connection, MHD_HTTP_CREATED, response);
    MHD_destroy_response(response);

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_AUTO | MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        return 1;
    }

    printf("Server is running on port %d\\n", PORT);

    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}
