
#include <iostream>
#include <string>
#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return crow::response(
            "<form method='post'>"
            "<input type='text' name='name'>"
            "<input type='submit' value='Submit'>"
            "</form>"
        );
    });

    CROW_ROUTE(app, "/").methods("POST"_method)
    ([](const crow::request& req){
        auto name = req.url_params.get("name");
        std::string response = "<h1>Hello, " + std::string(name) + "!</h1>";
        return crow::response(response);
    });

    app.port(8080).run();
    return 0;
}
