
#include <iostream>
#include <string>
#include <random>
#include <unordered_map>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

std::string generate_csrf_token() {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(charset) - 2);
    
    std::string token;
    for (int i = 0; i < 32; ++i) {
        token += charset[dis(gen)];
    }
    return token;
}

class csrf_handler {
public:
    csrf_handler() {
        m_listener = http_listener(U("http://localhost:8080"));
        m_listener.support(methods::GET, std::bind(&csrf_handler::handle_get, this, std::placeholders::_1));
        m_listener.support(methods::POST, std::bind(&csrf_handler::handle_post, this, std::placeholders::_1));
    }

    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

private:
    void handle_get(http_request request) {
        std::string csrf_token = generate_csrf_token();
        sessions[csrf_token] = true;

        std::string response_body = "<form method=\'post\'>"
                                    "<input type=\'hidden\' name=\'csrf_token\' value=\'" + csrf_token + "\'>"
                                    "<input type=\'submit\' value=\'Submit\'>"
                                    "</form>";

        request.reply(status_codes::OK, response_body, "text/html");
    }

    void handle_post(http_request request) {
        request.extract_json().then([this](pplx::task<json::value> task) {
            try {
                json::value json_data = task.get();
                if (json_data.has_field(U("csrf_token"))) {
                    std::string csrf_token = json_data[U("csrf_token")].as_string();
                    if (sessions.find(csrf_token) != sessions.end()) {
                        sessions.erase(csrf_token);
                        request.reply(status_codes::OK, "Form submitted successfully");
                    } else {
                        request.reply(status_codes::Forbidden, "CSRF token mismatch");
                    }
                } else {
                    request.reply(status_codes::BadRequest, "Missing CSRF token");
                }
            } catch (const std::exception &e) {
                request.reply(status_codes::InternalError, e.what());
            }
        });
    }

    http_listener m_listener;
    std::unordered_map<std::string, bool> sessions;
};

int main() {
    csrf_handler handler;
    handler.open().wait();
    std::cout << "Listening for requests at http://localhost:8080" << std::endl;
    
    std::string line;
    std::getline(std::cin, line);

    handler.close().wait();
    return 0;
}
