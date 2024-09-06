#include <iostream>
#include <string>
#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>

class hello : public cppcms::application {
public:
    hello(cppcms::service &srv) :
        cppcms::application(srv)
    {}

    void index() {
        if (request().request_method() == "POST") {
            response().out() <<
                "<html>\n"
                "<body>\n"
                "    <h1>You entered: " << request().post("user_input") << "</h1>\n"
                "    <a href=\"/\">Go back</a>\n"
                "</body>\n"
                "</html>\n";
        } else {
            response().out() <<
                "<html>\n"
                "<body>\n"
                "    <form method=\"post\" action=\"/\">\n"
                "        <input type=\"text\" name=\"user_input\">\n"
                "        <input type=\"submit\" value=\"Submit\">\n"
                "    </form>\n"
                "</body>\n"
                "</html>\n";
        }
    }
};

int main(int argc, char ** argv) {
    cppcms::service srv(argc, argv);
    srv.applications_pool().mount(
        cppcms::create_pool<hello>()
    );
    srv.run();
    return 0;
}