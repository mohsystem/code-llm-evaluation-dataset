#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>
#include <sqlite3.h>

#define PORT 8888

static int answer_to_connection(void *cls, struct MHD_Connection *connection,
                                const char *url, const char *method,
                                const char *version, const char *upload_data,
                                size_t *upload_data_size, void **con_cls) {
    sqlite3 *db;
    sqlite3_open("example.db", &db);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, email TEXT);", 0, 0, 0);

    const char *name = MHD_lookup_connection_value(connection, MHD_POSTDATA_KIND, "name");
    const char *email = MHD_lookup_connection_value(connection, MHD_POSTDATA_KIND, "email");

    if (name && email) {
        char *sql = sqlite3_mprintf("INSERT INTO users (name, email) VALUES (%Q, %Q);", name, email);
        sqlite3_exec(db, sql, 0, 0, 0);
        sqlite3_free(sql);

        const char *response_str = "User added successfully!";
        struct MHD_Response *response = MHD_create_response_from_buffer(strlen(response_str), (void *)response_str, MHD_RESPMEM_PERSISTENT);
        sqlite3_close(db);
        return MHD_queue_response(connection, MHD_HTTP_OK, response);
    }

    sqlite3_close(db);
    return MHD_NO;
}

int main() {
    struct MHD_Daemon *daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;

    getchar();  // Wait for user input to stop the server
    MHD_stop_daemon(daemon);
    return 0;
}