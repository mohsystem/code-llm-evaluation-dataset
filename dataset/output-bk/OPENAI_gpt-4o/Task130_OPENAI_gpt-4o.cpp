// C++ - Using Crow framework
#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api")
    ([] {
        crow::json::wvalue response;
        response["message"] = "Hello from Crow API with CORS enabled!";

        auto res = crow::response(response);
        res.add_header("Access-Control-Allow-Origin", "*");
        return res;
    });

    app.port(8080).multithreaded().run();
}