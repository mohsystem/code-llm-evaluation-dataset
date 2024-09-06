#include <stdio.h>
#include <microhttpd.h>

#define PORT 8888

int answer_to_connection(void *cls, struct MHD_Connection *connection, 
                          const char *url, const char *method, const char *version, 
                          const char *upload_data, size_t *upload_data_size, void **con_cls) {

    if (strcmp(method, "GET") != 0)
        return MHD_NO;

    const char *json_str = "{\"message\": \"This is a cross-origin response\"}";
    struct MHD_Response *response = MHD_create_response_from_buffer(strlen(json_str), (void*) json_str, MHD_RESPMEM_PERSISTENT);

    MHD_add_response_header(response, "Access-Control-Allow-Origin", "*");

    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL, 
                              &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;

    getchar(); // Close the server on user input
    MHD_stop_daemon(daemon);

    return 0;
}