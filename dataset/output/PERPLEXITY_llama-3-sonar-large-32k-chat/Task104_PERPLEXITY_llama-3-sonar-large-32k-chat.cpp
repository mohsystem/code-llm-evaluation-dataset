code here:
#include <iostream>
#include <string>
#include <vector>

int main() {
    int bufferSize = 10;
    std::vector<std::string> buffer(bufferSize);
    int index = 0;

    while (true) {
        std::cout << "Enter a value (or 'quit' to exit): ";
        std::string userInput;
        std::getline(std::cin, userInput);
        if (userInput == "quit") {
            break;
        }
        if (index < bufferSize) {
            buffer[index] = userInput;
            index++;
        } else {
            std::cout << "Buffer is full. Oldest value will be replaced." << std::endl;
            buffer.erase(buffer.begin());
            buffer.push_back(userInput);
        }
        std::cout << "Buffer: ";
        for (const auto& s : buffer) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}