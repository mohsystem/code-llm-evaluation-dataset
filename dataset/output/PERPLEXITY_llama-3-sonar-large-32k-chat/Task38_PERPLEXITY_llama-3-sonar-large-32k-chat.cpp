#include <iostream>
#include <string>
#include <cstdio>

int main() {
    std::cout << "Content-type: text/html\r
\r
";
    std::cout << "<html><body>";
    if (std::getenv("REQUEST_METHOD") && std::string(std::getenv("REQUEST_METHOD")) == "POST") {
        char name[1024];
        std::scanf("%s", name);
        std::cout << "<h1>Hello, " << name << "!</h1>";
    } else {
        std::cout << "<form action=\"\" method=\"post\">";
        std::cout << "    <input type=\"text\" name=\"name\" placeholder=\"Enter your name\">";
        std::cout << "    <input type=\"submit\" value=\"Submit\">";
        std::cout << "</form>";
    }
    std::cout << "</body></html>";
    return 0;
}