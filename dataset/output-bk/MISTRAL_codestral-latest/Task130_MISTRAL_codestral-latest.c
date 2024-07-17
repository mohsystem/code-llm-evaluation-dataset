#include <microhttpd.h>

static int answer_to_connection (void *cls, struct MHD_Connection *connection,
                                const char *url, const char *method,
                                const char *version, const char *upload_data,
                                size_t *upload_data_size, void **con_cls)
{
    struct MHD_Response *response;
    int ret;

    response = MHD_create_response_from_buffer (strlen ("Hello, cross-origin-world!"), (void *) "Hello, cross-origin-world!", MHD_RESPMEM_PERSISTENT);
    if (!response)
        return MHD_NO;

    MHD_add_response_header (response, "Access-Control-Allow-Origin", "*");
    MHD_add_response_header (response, "Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    MHD_add_response_header (response, "Access-Control-Allow-Headers", "Content-Type, Authorization");

    ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
    MHD_destroy_response (response);

    return ret;
}

int main (int argc, char *argv[])
{
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, 8080, NULL, NULL,
                               &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon)
        return 1;

    (void) getchar ();

    MHD_stop_daemon (daemon);
    return 0;
}