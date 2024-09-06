// C code using libmicrohttpd library
// Note: This is a simplified example and does not include error handling and security measures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>

#define UPLOAD_FOLDER "/path/to/upload/folder"

int upload_file(void *cls, struct MHD_Connection *connection,
                const char *upload_data, size_t *upload_data_size, void **con_cls) {
    static FILE *fp = NULL;
    static int received = 0;

    if (*con_cls == NULL) {
        fp = fopen("/tmp/uploaded_file", "w");
        if (fp == NULL) {
            return MHD_NO;
        }
        *con_cls = fp;
    } else {
        fp = *con_cls;
    }

    if (*upload_data_size != 0) {
        fwrite(upload_data, *upload_data_size, 1, fp);
        received += *upload_data_size;
        *upload_data_size = 0;
        return MHD_YES;
    } else {
        fclose(fp);
        *con_cls = NULL;
        return MHD_YES;
    }
}

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls) {
    if (0 == strcmp(method, "POST") && 0 == strcmp(url, "/upload")) {
        return upload_file(cls, connection, upload_data, upload_data_size, con_cls);
    } else {
        const char *page = "<html><body>Invalid request</body></html>";
        struct MHD_Response *response = MHD_create_response_from_buffer(strlen(page), (void *)page, MHD_RESPMEM_PERSISTENT);
        int ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
        MHD_destroy_response(response);
        return ret;
    }
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8080, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon) {
        return 1;
    }

    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}