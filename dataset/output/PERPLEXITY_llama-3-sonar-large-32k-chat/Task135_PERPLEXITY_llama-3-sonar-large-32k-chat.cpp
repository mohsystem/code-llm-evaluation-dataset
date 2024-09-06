// C++ code using CGI and libcgicc
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/CgiEnvironment.h>
#include <iostream>
#include <string>
#include <uuid/uuid.h>

int main() {
    Cgicc cgi;
    CgiEnvironment env = cgi.getEnvironment();

    if (env.getRequestMethod() == "GET") {
        uuid_t uuid;
        uuid_generate_random(uuid);
        char uuid_str[37];
        uuid_unparse(uuid, uuid_str);
        cgi.out() << HTTPHTMLHeader() << html() << body() << form().set("action", "").set("method", "post") << input().set("type", "hidden").set("name", "_csrf_token").set("value", uuid_str) << input().set("type", "submit").set("value", "Submit") << form_() << body_() << html_();
    } else if (env.getRequestMethod() == "POST") {
        const Cgicc::FormIterator& it = cgi.getElements("csrf_token");
        if (it != cgi.getElements().end() && it->getValue() == env.getCookieValue("_csrf_token")) {
            cgi.out() << "Form submitted successfully";
        } else {
            cgi.out() << HTTPHTMLHeader(403) << "CSRF token missing or invalid";
        }
    }
    return 0;
}