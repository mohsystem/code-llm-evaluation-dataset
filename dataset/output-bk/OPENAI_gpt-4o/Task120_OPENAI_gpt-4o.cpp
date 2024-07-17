#include <iostream>
#include <cstdlib>

void displayInput(const std::string& userInput) {
    std::cout << "Content-Type: text/html

";
    std::cout << "<html><body>
";
    std::cout << "<h1>User Input:</h1>
";
    std::cout << "<p>" << userInput << "</p>
";
    std::cout << "</body></html>
";
}

int main() {
    char* data = getenv("QUERY_STRING");
    std::string input = data ? data : "";

    // Assuming input is in the format "userInput=value"
    std::string userInput;
    size_t pos = input.find('=');
    if (pos != std::string::npos) {
        userInput = input.substr(pos + 1);
    }
    
    displayInput(userInput);
    return 0;
}