// C - Using Mongoose web server
#include "mongoose.h"

static void handle_request(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
    if (ev == MG_EV_HTTP_MSG) {
        mg_http_reply(c, 200,
                      "Content-Type: application/json\r
"
                      "Access-Control-Allow-Origin: *\r
",
                      "{\"message\":\"Hello from C API with CORS enabled!\"}
");
    }
}

int main(void) {
    struct mg_mgr mgr;
    struct mg_connection *c;

    mg_mgr_init(&mgr);
    c = mg_http_listen(&mgr, "http://localhost:8000", handle_request, &mgr);

    if (c == NULL) {
        printf("Error starting server!
");
        return 1;
    }

    for (;;) {
        mg_mgr_poll(&mgr, 1000);
    }

    mg_mgr_free(&mgr);
    return 0;
}