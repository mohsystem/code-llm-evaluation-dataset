// Include necessary libraries
#include <iostream>
#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/session_interface.h>

class settings : public cppcms::application {
public:
    settings(cppcms::service &srv) : cppcms::application(srv) {}
    void main(std::string url);
};

void settings::main(std::string /*url*/) {
    response().out() << "<html><body>";

    if (request().request_method() == "POST") {
        std::string csrf_token = session().get("_csrf_token");
        session().erase("_csrf_token");
        std::string request_token = request().post("_csrf_token");

        if (csrf_token.empty() || csrf_token != request_token) {
            response().status(403);
            response().out() << "CSRF token is missing or incorrect";
        } else {
            // Save settings logic here
            response().out() << "Settings updated!";
        }
    } else {
        std::string csrf_token = "aCSRFtoken";
        session().set("_csrf_token", csrf_token);
        response().out() <<
            "<form method='POST' action='/settings'>" <<
            "<input type='hidden' name='_csrf_token' value='" << csrf_token << "'/>" <<
            "<input type='text' name='username' placeholder='Username'/>" <<
            "<button type='submit'>Save</button>" <<
            "</form>";
    }

    response().out() << "</body></html>";
}

int main(int argc, char *argv[]) {
    try {
        cppcms::service app(argc, argv);
        app.applications_pool().mount(cppcms::applications_factory<settings>());
        app.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}