
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>

#define PAGE "<html><body>"\\
             "<form action=\\"/\\" method=\\"post\\">"\\
             "Name: <input type=\\"text\\" name=\\"name\\"/>"\\
             "<input type=\\"submit\\" value=\\"Submit\\"/>"\\
             "</form>"\\
             "</body></html>"

#define MAX_NAME_LENGTH 64

static int answer_to_connection(void *cls, struct MHD_Connection *connection,
                                const char *url, const char *method,
                                const char *version, const char *upload_data,
                                size_t *upload_data_size, void **con_cls)
{
    static int dummy;
    struct MHD_Response *response;
    int ret;

    if (strcmp(method, "GET") == 0) {
        response = MHD_create_response_from_buffer(strlen(PAGE),
                                                   (void *)PAGE,
                                                   MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
        return ret;
    }

    if (strcmp(method, "POST") == 0) {
        if (*con_cls == NULL) {
            *con_cls = &dummy;
            return MHD_YES;
        }
        if (*upload_data_size != 0) {
            char name[MAX_NAME_LENGTH];
            if (MHD_post_process(connection, upload_data, *upload_data_size,
                                 "name", name, MAX_NAME_LENGTH) == MHD_NO) {
                return MHD_NO;
            }
            *upload_data_size = 0;
            char *page = malloc(strlen("<html><body><h1>Hello, !</h1></body></html>") + strlen(name) + 1);
            sprintf(page, "<html><body><h1>Hello, %s!</h1></body></html>", name);
            response = MHD_create_response_from_buffer(strlen(page),
                                                       (void *)page,
                                                       MHD_RESPMEM_MUST_FREE);
            ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
            MHD_destroy_response(response);
            return ret;
        }
    }

    return MHD_NO;
}

int main()
{
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_AUTO | MHD_USE_INTERNAL_POLLING_THREAD,
                              8080, NULL, NULL,
                              &answer_to_connection, NULL,
                              MHD_OPTION_END);
    if (daemon == NULL)
        return 1;

    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}
