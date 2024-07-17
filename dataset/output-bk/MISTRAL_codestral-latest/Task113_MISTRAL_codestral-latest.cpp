#include <iostream>
#include <string>

int main() {
    std::string input;
    std::string result = "";

    std::cout << "Enter strings to concatenate (enter 'end' to stop):
";
    std::getline(std::cin, input);

    while (input != "end") {
        result += input;
        std::getline(std::cin, input);
    }

    std::cout << "Concatenated string: " << result << std::endl;

    return 0;
}