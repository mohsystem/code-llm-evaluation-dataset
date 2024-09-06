
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <sstream>
#include <iomanip>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

std::string generate_csrf_token() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    const char *hex_digits = "0123456789abcdef";
    std::string token;
    for (int i = 0; i < 32; ++i) {
        token += hex_digits[dis(gen)];
    }
    return token;
}

class CSRFProtectionHandler {
private:
    std::map<std::string, std::string> session_tokens;

public:
    void handle_get(http_request request) {
        std::string csrf_token = generate_csrf_token();
        session_tokens[request.headers()["Cookie"]] = csrf_token;

        std::stringstream ss;
        ss << "<form method='post'>"
           << "<input type='hidden' name='_csrf_token' value='" << csrf_token << "'>"
           << "<input type='submit' value='Submit'>"
           << "</form>";

        request.reply(status_codes::OK, ss.str(), "text/html");
    }

    void handle_post(http_request request) {
        request.extract_json().then([=](json::value body) {
            auto session_cookie = request.headers()["Cookie"];
            auto stored_token = session_tokens[session_cookie];
            auto received_token = body["_csrf_token"].as_string();

            if (stored_token == received_token) {
                request.reply(status_codes::OK, "Form submitted successfully!");
            } else {
                request.reply(status_codes::Forbidden, "CSRF token validation failed");
            }
        });
    }
};

int main() {
    http_listener listener("http://localhost:8080");
    CSRFProtectionHandler handler;

    listener.support(methods::GET, std::bind(&CSRFProtectionHandler::handle_get, &handler, std::placeholders::_1));
    listener.support(methods::POST, std::bind(&CSRFProtectionHandler::handle_post, &handler, std::placeholders::_1));

    try {
        listener.open().wait();
        std::cout << "Listening for requests at: " << listener.uri().to_string() << std::endl;
        while (true);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
