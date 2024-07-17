
#include <iostream>
#include <string>
#include <algorithm>

const int BUFFER_SIZE = 20;

int main() {
    char buffer[BUFFER_SIZE];
    std::string input;

    std::cout << "Enter a string (max " << BUFFER_SIZE << " characters):" << std::endl;
    std::getline(std::cin, input);

    int length = std::min(static_cast<int>(input.length()), BUFFER_SIZE);
    std::copy_n(input.begin(), length, buffer);

    std::cout << "Buffer contents:" << std::endl;
    std::cout << std::string(buffer, length) << std::endl;

    return 0;
}
