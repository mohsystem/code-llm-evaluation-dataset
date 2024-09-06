
#include <crow.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/data")
    ([](const crow::request& req) {
        crow::json::wvalue response;
        response["message"] = "This is CORS-enabled data";

        crow::response res(response);
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
        return res;
    });

    app.port(8080).run();
    return 0;
}
