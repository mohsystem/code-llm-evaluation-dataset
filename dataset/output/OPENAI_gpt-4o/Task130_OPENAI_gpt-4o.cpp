#include <iostream>
#include <httplib.h>

int main() {
    httplib::Server svr;
    
    svr.Get("/api/data", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("{\"message\": \"This is a cross-origin response\"}", "application/json");
    });

    svr.listen("localhost", 1234);
    
    return 0;
}