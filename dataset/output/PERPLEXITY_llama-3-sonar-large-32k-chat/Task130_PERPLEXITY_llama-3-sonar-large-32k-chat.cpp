code here:
// C++ does not have built-in support for web development, so we'll use a library like Poco
// This example assumes you have Poco installed and configured

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

class CORSRequestHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        response.set("Access-Control-Allow-Origin", "*");
        response.set("Access-Control-Allow-Headers", "origin, content-type, accept, authorization");
        response.set("Access-Control-Allow-Credentials", "true");
        response.set("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS, HEAD");
        response.set("Access-Control-Max-Age", "1209600");

        // Handle the request
        response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        response.setContentType("text/plain");
        response.sendBuffer("Hello, World!");
    }
};

int main() {
    Poco::Net::ServerSocket svs(8080);
    Poco::Net::HTTPServer srv(new CORSRequestHandlerFactory, svs, new Poco::Net::HTTPServerParams);
    srv.start();
    srv.run();
    return 0;
}