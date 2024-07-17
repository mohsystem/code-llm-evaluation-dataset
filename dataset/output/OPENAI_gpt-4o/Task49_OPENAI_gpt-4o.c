#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>
#include <sqlite3.h>

#define PORT 8080

static int store_data(const char *data) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("userdata.db", &db);
    if (rc != SQLITE_OK) {
        return rc;
    }
    char *sql = "CREATE TABLE IF NOT EXISTS Users (Data TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return rc;
    }
    sqlite3_stmt *stmt;
    sql = "INSERT INTO Users (Data) VALUES (?);";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return rc;
    }
    sqlite3_bind_text(stmt, 1, data, -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return (rc == SQLITE_DONE) ? SQLITE_OK : rc;
}

static int handle_post(void *cls, struct MHD_Connection *connection, 
    const char *url, const char *method, const char *version, 
    const char *upload_data, size_t *upload_data_size, void **ptr) {
    static int aptr;
    if (0 != strcmp(method, "POST")) {
        return MHD_NO; 
    }
    if (&aptr != *ptr) {
        *ptr = &aptr; 
        return MHD_YES; 
    }
    if (*upload_data_size != 0) {
        store_data(upload_data);
        *upload_data_size = 0; 
        return MHD_YES;
    }
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(strlen("Data stored successfully"), 
               (void*)"Data stored successfully", MHD_RESPMEM_PERSISTENT);
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL, 
                              &handle_post, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;
    (void)getchar();
    MHD_stop_daemon(daemon);
    return 0;
}