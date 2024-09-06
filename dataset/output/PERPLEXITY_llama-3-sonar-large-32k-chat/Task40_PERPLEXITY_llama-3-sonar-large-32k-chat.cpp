// C++ (using CGI and HTML templates)
#include <iostream>
#include <string>
#include <map>
#include <cgicc/Cgicc.h>

int main() {
    Cgicc cgi;
    std::string csrfToken = "random_token_here";
    if (cgi.getRequestMethod() == "POST") {
        if (!cgi["csrf_token"].isEmpty() && cgi["csrf_token"] == csrfToken) {
            // Update user settings here
            std::cout << "Settings updated successfully";
        } else {
            std::cout << "CSRF token is invalid";
        }
    } else {
        std::cout << "Content-type:text/html\r\n\r\n";
        std::cout << "<form action=\"\" method=\"post\">";
        std::cout << "<input type=\"hidden\" name=\"csrf_token\" value=\"" << csrfToken << "\">";
        std::cout << "<label>Username:</label>";
        std::cout << "<input type=\"text\" name=\"username\"><br><br>";
        std::cout << "<label>Email:</label>";
        std::cout << "<input type=\"email\" name=\"email\"><br><br>";
        std::cout << "<input type=\"submit\" value=\"Update Settings\">";
        std::cout << "</form>";
    }
    return 0;
}