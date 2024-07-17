#include <iostream>
#include <cstring>

void run_CPP(int bufferSize, char input[]) {
    char buffer[10] = {0};
    std::cout << "Enter input (C++): ";
    std::cin.getline(input, bufferSize);
    strncpy(buffer, input, bufferSize - 1);
    std::cout << "Buffer contents (C++): " << buffer << std::endl;
}