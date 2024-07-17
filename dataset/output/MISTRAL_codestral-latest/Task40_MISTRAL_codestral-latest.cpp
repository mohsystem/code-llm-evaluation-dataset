// C++ example (using CppCMS)
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>

class MyApp : public cppcms::application {
public:
    MyApp(cppcms::service &srv) : cppcms::application(srv) {}
    void update_settings();
};

void MyApp::update_settings() {
    if (request().request_method() == "POST") {
        std::string csrfToken = request().post("csrf_token");
        if (csrfToken == session().get<std::string>("csrf_token")) {
            // Your code to update settings here
            response().out() << "Settings updated";
        } else {
            response().status(cppcms::http::response::forbidden);
            response().out() << "Invalid CSRF token";
        }
    }
}