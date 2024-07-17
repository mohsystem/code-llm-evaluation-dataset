// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mongoose.h"

static const char *s_html =
"<html><body> "
"<form action=\"/terminate\" method=\"POST\">"
"Session ID: <input type=\"text\" name=\"sessionId\">"
"<input type=\"submit\" value=\"Terminate\">"
"</form>"
"</body></html>";

static void handle_create(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
    if (ev == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message *) ev_data;
        if (mg_http_match_uri(hm, "/")) {
            char url[256];
            snprintf(url, sizeof(url), "%s", c->label);  // For simplicity
            mg_http_reply(c, 200, "Content-Type: text/html\r
", s_html);
        }
    }
}

static void handle_terminate(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
    if (ev == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message *) ev_data;
        if (mg_http_match_uri(hm, "/terminate")) {
            mg_http_reply(c, 200, "Content-Type: text/html\r
", "Session terminated
");
        }
    }
}

int main(void) {
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);
    mg_http_listen(&mgr, "http://localhost:8000", handle_create, NULL);
    mg_http_listen(&mgr, "http://localhost:8000/terminate", handle_terminate, NULL);
    for (;;) mg_mgr_poll(&mgr, 1000);
    mg_mgr_free(&mgr);
    return 0;
}