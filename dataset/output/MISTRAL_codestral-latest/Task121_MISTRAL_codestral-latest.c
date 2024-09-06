// C (Using libmicrohttpd)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>

#define PAGE "<html><body><form action='/upload' method='post' enctype='multipart/form-data'>" \
              "<input type='file' name='file'/><br/>" \
              "<input type='submit' value='Upload'/></form></body></html>"

int post_handler(void *cls, struct MHD_Connection *connection,
                 const char *url, const char *method,
                 const char *version, const char *upload_data,
                 size_t *upload_data_size, void **con_cls) {
    static int dummy;
    FILE *fp;
    const char *filename = "/path/to/the/uploads/uploaded_file";

    if (&dummy != *con_cls) {
        /* The first time only the headers are valid,
           do not respond in the first round... */
        *con_cls = &dummy;
        return MHD_YES;
    }

    if (*upload_data_size != 0) {
        /* Open file for writing */
        fp = fopen(filename, "a");
        if (fp == NULL) {
            printf("Failed to open file for writing\n");
            return MHD_NO;
        }

        /* Write data to file */
        fwrite(upload_data, sizeof(char), *upload_data_size, fp);
        fclose(fp);

        /* Reset the buffer pointer */
        *upload_data_size = 0;
        return MHD_YES;
    } else {
        struct MHD_Response *response;
        int ret;

        /* Upload completed, return a response */
        response = MHD_create_response_from_buffer(strlen(PAGE), (void *)PAGE, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
        MHD_destroy_response(response);
        return ret;
    }
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8888, NULL, NULL,
                              &post_handler, NULL, MHD_OPTION_END);
    if (NULL == daemon)
        return 1;

    (void)getchar();

    MHD_stop_daemon(daemon);
    return 0;
}