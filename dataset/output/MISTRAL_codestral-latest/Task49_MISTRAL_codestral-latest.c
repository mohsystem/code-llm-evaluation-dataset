// C (using libmicrohttpd)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <microhttpd.h>
#include <jansson.h>

#define PAGE "<html><head><title>User Added</title></head><body>User added successfully</body></html>"

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls) {
    if (0 != strcmp(method, "POST"))
        return MHD_NO;
    if (0 != strcmp(url, "/user"))
        return MHD_NO;
    if (*upload_data_size != 0) {
        json_t *root;
        json_error_t error;
        root = json_loads(upload_data, 0, &error);
        if (root) {
            json_t *name = json_object_get(root, "name");
            json_t *email = json_object_get(root, "email");
            if (name && email) {
                sqlite3 *db;
                int rc = sqlite3_open("test.db", &db);
                if (rc) {
                    return MHD_NO;
                }
                char *zErrMsg = 0;
                char *sql = sqlite3_mprintf("INSERT INTO users(name, email) VALUES('%q', '%q');", json_string_value(name), json_string_value(email));
                rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);
                sqlite3_free(sql);
                if (rc != SQLITE_OK) {
                    return MHD_NO;
                }
                sqlite3_close(db);
            }
            json_decref(root);
        }
        *upload_data_size = 0;
        return MHD_YES;
    } else {
        struct MHD_Response *response;
        int ret;
        response = MHD_create_response_from_buffer(strlen(PAGE), (void *)PAGE, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
        return ret;
    }
}

int main() {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8888, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon)
        return 1;
    (void)getchar();
    MHD_stop_daemon(daemon);
    return 0;
}