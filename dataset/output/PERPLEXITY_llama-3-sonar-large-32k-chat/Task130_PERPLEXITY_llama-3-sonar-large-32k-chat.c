code here:
// C does not have built-in support for web development, so we'll use a library like libonion
// This example assumes you have libonion installed and configured

#include <onion/log.h>
#include <onion/request.h>
#include <onion/response.h>
#include <onion/router.h>

int main() {
    onion *o = onion_new();
    onion_set_timeout(o, 10);

    onion_router *r = onion_router_new();
    onion_router_add(r, "GET", "/", cors_handler);
    onion_add_router(o, r);

    onion_listen(o, "8080");

    onion_free(o);
    return 0;
}

void cors_handler/onion_request *req, onion_response *res) {
    onion_response_set_header(res, "Access-Control-Allow-Origin", "*");
    onion_response_set_header(res, "Access-Control-Allow-Headers", "origin, content-type, accept, authorization");
    onion_response_set_header(res, "Access-Control-Allow-Credentials", "true");
    onion_response_set_header(res, "Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS, HEAD");
    onion_response_set_header(res, "Access-Control-Max-Age", "1209600");

    onion_response_set_code(res, 200);
    onion_response_write(res, "Hello, World!", 13);
}