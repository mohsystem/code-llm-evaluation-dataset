#include <iostream>
#include <string>
#include <uuid/uuid.h>
#include <cgicc/Cgicc.h>

int main() {
    Cgicc cgi;
    std::string token = uuid_generate();
    cgi.setCookie("csrf_token", token);
    std::cout << "Content-type: text/html\r
\r
";
    std::cout << "<form action='' method='post'>";
    std::cout << "<input type='hidden' name='_csrf_token' value='" << token << "'>";
    std::cout << "<input type='submit' value='Submit'>";
    std::cout << "</form>";

    if (cgi.getRequestMethod() == "POST") {
        std::string postedToken = cgi["csrf_token"];
        if (postedToken != token) {
            std::cout << "Status: 403 Forbidden\r
\r
";
            std::cout << "CSRF token missing or invalid";
        } else {
            std::cout << "Form submitted successfully";
        }
    }
    return 0;
}