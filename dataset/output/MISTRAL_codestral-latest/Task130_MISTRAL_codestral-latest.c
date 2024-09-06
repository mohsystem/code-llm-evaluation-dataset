// C does not have built-in support for CORS, so you would need to manually set the headers.
// This example uses libonion, a lightweight HTTP server library.

#include <onion/onion.h>
#include <onion/log.h>
#include <onion/request.h>
#include <onion/response.h>

void handle_request(void *_, onion_request *req, onion_response *res) {
    onion_response_set_header(res, "Access-Control-Allow-Origin", "http://example.com");
    onion_response_write0(res, "API response");
}

int main() {
    onion *o = onion_new(O_THRPOOL);
    onion_url *url = onion_root_url(o);
    onion_url_add(url, "", handle_request);
    onion_listen(o, "0.0.0.0", 8080);
    onion_free(o);
    return 0;
}