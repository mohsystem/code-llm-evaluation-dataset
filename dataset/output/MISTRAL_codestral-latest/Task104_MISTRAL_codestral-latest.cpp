#include <iostream>
#include <cstring>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];

    std::cout << "Enter a string: ";
    std::cin.getline(input, BUFFER_SIZE);

    if (std::strlen(input) > BUFFER_SIZE) {
        std::cout << "Input is too long for the buffer.
";
    } else {
        std::strcpy(buffer, input);
        std::cout << "Input stored in buffer: " << buffer << "
";
    }

    return 0;
}