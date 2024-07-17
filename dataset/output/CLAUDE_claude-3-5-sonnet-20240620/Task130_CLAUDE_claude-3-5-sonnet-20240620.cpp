
#include <crow.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/data")
    ([](const crow::request& req, crow::response& res) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
        res.write("This is CORS-enabled data");
        res.end();
    });

    app.port(5000).run();
    return 0;
}
