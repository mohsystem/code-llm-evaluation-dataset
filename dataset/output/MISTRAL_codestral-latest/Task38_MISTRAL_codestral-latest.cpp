// C++ CGI web application
#include <iostream>
#include <cstdlib>
#include <cstring>

int main() {
    char* data = getenv("QUERY_STRING");
    if (data != nullptr) {
        char* userInput = strstr(data, "user_input=");
        if (userInput != nullptr) {
            userInput += strlen("user_input=");
            std::cout << "Content-type: text/html\n\n";
            std::cout << "<html><body>";
            std::cout << "<h1>Your input: " << userInput << "</h1>";
            std::cout << "</body></html>";
        }
    }
    return 0;
}