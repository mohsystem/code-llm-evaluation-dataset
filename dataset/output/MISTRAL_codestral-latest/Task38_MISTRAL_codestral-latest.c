// C code using libmicrohttpd library
// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>

#define PAGE "<html><body><form action='/' method='post'>" \
              "<input type='text' name='user_input'>" \
              "<input type='submit' value='Submit'>" \
              "</form></body></html>"

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls) {
    if (strcmp(method, "POST") == 0) {
        char *user_input = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "user_input");
        if (user_input != NULL) {
            char *response = malloc(strlen(PAGE) + strlen(user_input) + 30);
            sprintf(response, "<html><body>You entered: %s</body></html>", user_input);
            struct MHD_Response *resp = MHD_create_response_from_buffer(strlen(response), (void *)response, MHD_RESPMEM_MUST_FREE);
            int ret = MHD_queue_response(connection, MHD_HTTP_OK, resp);
            MHD_destroy_response(resp);
            return ret;
        }
    }
    struct MHD_Response *resp = MHD_create_response_from_buffer(strlen(PAGE), (void *)PAGE, MHD_RESPMEM_PERSISTENT);
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, resp);
    MHD_destroy_response(resp);
    return ret;
}

int main(int argc, char *argv[]) {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8888, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon)
        return 1;
    getchar();
    MHD_stop_daemon(daemon);
    return 0;
}