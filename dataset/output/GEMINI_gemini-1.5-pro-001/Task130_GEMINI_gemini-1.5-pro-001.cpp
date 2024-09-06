#include <iostream>

#include <pistache/endpoint.h>
#include <pistache/router.h>

using namespace Pistache;

class MyHandler : public Http::Handler {
public:
    HTTP_PROTOTYPE(MyHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override {
        if (request.resource() == "/api/data") {
            response.headers().add<Http::Header::AccessControlAllowOrigin>("*");
            response.send(Http::Code::Ok, "{\"name\": \"John Doe\", \"age\": 30}");
        } else {
            response.send(Http::Code::Not_Found);
        }
    }
};

int main() {
    Address addr(Ipv4::any(), Port(9080));
    auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Http::make_handler<MyHandler>());
    server.serve();
}