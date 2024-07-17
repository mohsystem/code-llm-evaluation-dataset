// C example using the libonion library for HTTP
#include <onion/onion.h>
#include <onion/log.h>
#include <onion/request.h>
#include <onion/response.h>
#include <onion/session.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void handle_request(void *unused, OnionRequest *req, OnionResponse *res) {
    if (onion_request_get_flags(req) & OR_POST) {
        OnionSession *session = onion_request_get_session(req);
        if (session) {
            const char *token = onion_session_get_data(session, "csrf_token");
            const char *form_token = onion_request_get_post(req, "csrf_token");
            if (token && form_token && strcmp(token, form_token) == 0) {
                // Process the funds transfer
            } else {
                onion_response_set_status(res, 403);
            }
        } else {
            onion_response_set_status(res, 403);
        }
    } else if (onion_request_get_flags(req) & OR_GET) {
        OnionSession *session = onion_request_get_session(req);
        if (!session) {
            session = onion_session_generate();
            onion_request_set_session(req, session);
        }
        char token[25];
        for (int i = 0; i < 24; i++) {
            token[i] = rand() % 256;
        }
        token[24] = '\0';
        onion_session_set_data(session, "csrf_token", token);
        // Render the form with the CSRF token
    }
}

int main() {
    srand(time(NULL));
    Onion *onion = onion_new(O_POOL);
    onion_set_log_level(onion, ONION_LOG_FATAL);
    onion_url *url = onion_root_url(onion);
    onion_url_add(url, "", handle_request, NULL);
    onion_listen(onion);
    onion_free(onion);
    return 0;
}