// CPP code using CGI and cookies (not recommended for web development)
#include <iostream>
#include <string>
#include <map>
#include <cgi/cgi.h>

int main() {
    Cgi cgi;
    std::map<std::string, std::string> cookies = cgi.get_cookies();
    std::string username, password;
    if (cgi.request_method() == "POST") {
        username = cgi["username"];
        password = cgi["password"];
        if (username == "admin" && password == "password") {
            cgi.set_cookie("username", username);
            cgi.header("Location: home");
            return 0;
        }
    }
    std::string path = cgi.path_info();
    if (path == "/login") {
        std::cout << "Content-type: text/html\r\n\r\n";
        std::cout << "<form action=\"\" method=\"post\">";
        std::cout << "Username: <input type=\"text\" name=\"username\"><br>";
        std::cout << "Password: <input type=\"password\" name=\"password\"><br>";
        std::cout << "<input type=\"submit\" value=\"Login\">";
        std::cout << "</form>";
    } else if (path == "/home") {
        if (cookies.find("username") != cookies.end()) {
            std::cout << "Content-type: text/html\r\n\r\n";
            std::cout << "Welcome, " << cookies["username"];
        } else {
            cgi.header("Location: login");
        }
    } else if (path == "/logout") {
        cgi.set_cookie("username", "", 0);
        cgi.header("Location: login");
    }
    return 0;
}