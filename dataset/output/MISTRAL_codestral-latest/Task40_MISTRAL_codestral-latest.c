// C example (using libmicrohttpd)
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>

#define POSTBUFFERSIZE  512
#define GET             0
#define POST            1

int update_settings(void *cls, struct MHD_Connection *connection,
                    const char *url, const char *method,
                    const char *version, const char *upload_data,
                    size_t *upload_data_size, void **con_cls) {
    if (strcmp(method, "POST") == 0) {
        char *csrfToken = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "csrf_token");
        if (csrfToken != NULL && strcmp(csrfToken, "your-csrf-token") == 0) {
            // Your code to update settings here
            free(csrfToken);
            return MHD_create_response_from_buffer(strlen("Settings updated"), (void *)"Settings updated", MHD_RESPMEM_PERSISTENT);
        } else {
            free(csrfToken);
            return MHD_create_response_from_buffer(strlen("Invalid CSRF token"), (void *)"Invalid CSRF token", MHD_RESPMEM_PERSISTENT);
        }
    }
    return MHD_NO;
}