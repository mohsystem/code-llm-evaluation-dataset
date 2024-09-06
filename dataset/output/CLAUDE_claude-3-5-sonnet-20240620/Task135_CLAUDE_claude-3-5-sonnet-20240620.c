
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <microhttpd.h>

#define MAX_TOKEN_LENGTH 33
#define MAX_PAGE_SIZE 1024

static char csrf_token[MAX_TOKEN_LENGTH];

static void generate_csrf_token() {
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int charset_size = sizeof(charset) - 1;

    srand(time(NULL));
    for (int i = 0; i < MAX_TOKEN_LENGTH - 1; i++) {
        csrf_token[i] = charset[rand() % charset_size];
    }
    csrf_token[MAX_TOKEN_LENGTH - 1] = '\\0';
}

static int handle_request(void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
    static int dummy;
    struct MHD_Response *response;
    int ret;

    if (&dummy != *con_cls) {
        *con_cls = &dummy;
        return MHD_YES;
    }

    if (strcmp(method, "GET") == 0) {
        generate_csrf_token();
        char page[MAX_PAGE_SIZE];
        snprintf(page, MAX_PAGE_SIZE,
                 "<form method='POST'>"
                 "<input type='hidden' name='csrf_token' value='%s'>"
                 "<input type='submit' value='Submit'>"
                 "</form>", csrf_token);

        response = MHD_create_response_from_buffer(strlen(page), (void*)page, MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
    } else if (strcmp(method, "POST") == 0) {
        const char *received_token = MHD_lookup_connection_value(connection, MHD_POSTDATA_KIND, "csrf_token");

        if (received_token && strcmp(received_token, csrf_token) == 0) {
            const char *success_msg = "Form submitted successfully!";
            response = MHD_create_response_from_buffer(strlen(success_msg), (void*)success_msg, MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        } else {
            const char *error_msg = "CSRF token validation failed";
            response = MHD_create_response_from_buffer(strlen(error_msg), (void*)error_msg, MHD_RESPMEM_PERSISTENT);
            ret = MHD_queue_response(connection, MHD_HTTP_FORBIDDEN, response);
        }
        MHD_destroy_response(response);
    } else {
        return MHD_NO;
    }

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD, 8080, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        return 1;
    }

    printf("Server running on port 8080. Press Enter to quit.\\n");
    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}
