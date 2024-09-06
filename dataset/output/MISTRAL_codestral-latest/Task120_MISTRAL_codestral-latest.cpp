// CPP (using C++ with CGI)
#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "Content-type: text/html\n\n";
    std::cout << "<html><body>";
    char* userInput = std::getenv("QUERY_STRING");
    if (userInput != nullptr) {
        std::cout << "<p>User input: " << userInput << "</p>";
    } else {
        std::cout << "<form method='GET'><input type='text' name='user_input'><input type='submit' value='Submit'></form>";
    }
    std::cout << "</body></html>";
    return 0;
}