
#include <iostream>
#include <string>
#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([](const crow::request& req) {
        std::string user_input = "";
        if (req.method == crow::HTTPMethod::Post) {
            user_input = req.get_body_params().get("user_input");
        }

        std::string html = R"(\n            <!DOCTYPE html>\n            <html>\n            <body>\n                <form method="post">\n                    <input type="text" name="user_input">\n                    <input type="submit" value="Submit">\n                </form>\n                <p>)" + user_input + R"(</p>\n            </body>\n            </html>\n        )";

        return crow::response(html);
    });

    app.port(8080).run();
    return 0;
}
