// C++ code using CppCMS framework
// main.cpp
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>

class MyApp : public cppcms::application {
public:
    MyApp(cppcms::service &srv) : cppcms::application(srv) {
        dispatcher().assign("/", &MyApp::home, this);
        dispatcher().assign("/submit", &MyApp::submit, this);
    }

    void home() {
        response().out() << "<form action='/submit' method='post'>"
                          << "<input type='text' name='user_input'>"
                          << "<input type='submit' value='Submit'>"
                          << "</form>";
    }

    void submit() {
        std::string userInput = request().post("user_input");
        response().out() << "You entered: " << userInput;
    }
};

int main(int argc, char **argv) {
    try {
        cppcms::service srv(argc, argv);
        srv.applications_pool().mount(cppcms::applications_factory<MyApp>());
        srv.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}