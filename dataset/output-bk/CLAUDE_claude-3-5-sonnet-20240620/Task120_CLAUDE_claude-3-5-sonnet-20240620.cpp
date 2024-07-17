
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string method = std::getenv("REQUEST_METHOD");
    std::string input;

    std::cout << "Content-Type: text/html\
\
";
    std::cout << "<html><body>";

    if (method == "POST") {
        std::getline(std::cin, input);
        size_t pos = input.find(\'=\');
        std::string user_input = input.substr(pos + 1);
        
        std::cout << "<h2>User Input:</h2>";
        std::cout << "<p>" << user_input << "</p>";
    } else {
        std::cout << "<h2>Enter your input:</h2>";
        std::cout << "<form method=\'post\'>";
        std::cout << "<input type=\'text\' name=\'userInput\'>";
        std::cout << "<input type=\'submit\' value=\'Submit\'>";
        std::cout << "</form>";
    }

    std::cout << "</body></html>";
    return 0;
}
