
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <microhttpd.h>

#define MAX_TOKEN_LENGTH 33
#define MAX_PAGE_SIZE 1024

static char csrf_token[MAX_TOKEN_LENGTH];

static void generate_csrf_token() {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i;
    
    srand(time(NULL));
    for (i = 0; i < MAX_TOKEN_LENGTH - 1; i++) {
        csrf_token[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    csrf_token[MAX_TOKEN_LENGTH - 1] = \'\\0\';
}

static int handle_request(void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
    struct MHD_Response *response;
    int ret;
    char page[MAX_PAGE_SIZE];

    if (strcmp(method, "GET") == 0) {
        generate_csrf_token();
        snprintf(page, MAX_PAGE_SIZE,
                 "<html><body>"
                 "<form method=\'POST\'>"
                 "<input type=\'hidden\' name=\'csrf_token\' value=\'%s\'>"
                 "<input type=\'submit\' value=\'Submit\'>"
                 "</form></body></html>",
                 csrf_token);

        response = MHD_create_response_from_buffer(strlen(page),
                                                   (void*) page,
                                                   MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
    } else if (strcmp(method, "POST") == 0) {
        const char *post_csrf_token = MHD_lookup_connection_value(connection, MHD_POSTDATA_KIND, "csrf_token");

        if (post_csrf_token && strcmp(post_csrf_token, csrf_token) == 0) {
            snprintf(page, MAX_PAGE_SIZE, "Form submitted successfully");
        } else {
            snprintf(page, MAX_PAGE_SIZE, "CSRF token mismatch");
        }

        response = MHD_create_response_from_buffer(strlen(page),
                                                   (void*) page,
                                                   MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
    } else {
        response = MHD_create_response_from_buffer(0, NULL, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_METHOD_NOT_ALLOWED, response);
        MHD_destroy_response(response);
    }

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_AUTO | MHD_USE_INTERNAL_POLLING_THREAD, 8080, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        return 1;
    }

    printf("Server running on port 8080. Press ENTER to quit.\
");
    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}
