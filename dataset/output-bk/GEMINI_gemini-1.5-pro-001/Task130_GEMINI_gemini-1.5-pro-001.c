#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <microhttpd.h>

#define PORT 8080

static int handle_request(void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
  if (strcmp(method, "GET") == 0 && strcmp(url, "/api/data") == 0) {
    const char *response_body = "{\"name\": \"John Doe\", \"age\": 30}";
    struct MHD_Response *response = MHD_create_response_from_buffer(
        strlen(response_body), (void *)response_body, MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(response, "Content-Type", "application/json");
    MHD_add_response_header(response, "Access-Control-Allow-Origin", "*");
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
  }

  return MHD_NO;
}

int main(void) {
  struct MHD_Daemon *daemon;
  daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                            &handle_request, NULL, MHD_OPTION_END);
  if (daemon == NULL) {
    return 1;
  }

  printf("Server started at http://localhost:%d
", PORT);
  getchar();
  MHD_stop_daemon(daemon);
  return 0;
}