// C (using libmicrohttpd)
#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE "<html><body><form method='post'><input name='user_input'><input type='submit' value='Submit'></form></body></html>"

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls) {
    if (0 == strcmp(method, "POST")) {
        if (*upload_data_size != 0) {
            char *page = malloc(sizeof(char) * (*upload_data_size + 1));
            memcpy(page, upload_data, *upload_data_size);
            page[*upload_data_size] = '\0';
            struct MHD_Response *response = MHD_create_response_from_buffer(strlen(page), page, MHD_RESPMEM_MUST_FREE);
            int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
            MHD_destroy_response(response);
            return ret;
        }
    }
    struct MHD_Response *response = MHD_create_response_from_buffer(strlen(PAGE), PAGE, MHD_RESPMEM_PERSISTENT);
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8888, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;
    getchar();
    MHD_stop_daemon(daemon);
    return 0;
}