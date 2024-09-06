
#include <iostream>
#include <cstring>

const int BUFFER_SIZE = 100;

void handleUserInput(char* buffer, int bufferSize) {
    std::cout << "Enter a string (max " << bufferSize - 1 << " characters): ";
    std::cin.getline(buffer, bufferSize);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');
        std::cout << "Input too long. Truncated to " << bufferSize - 1 << " characters." << std::endl;
    }

    std::cout << "You entered: " << buffer << std::endl;
}

int main() {
    char buffer[BUFFER_SIZE];
    handleUserInput(buffer, BUFFER_SIZE);
    return 0;
}
