code here:
#include <iostream>

int main() {
    int bufferSize;
    std::cout << "Enter the buffer size: ";
    std::cin >> bufferSize;
    int* buffer = new int[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = i;
    }
    while (true) {
        int index;
        std::cout << "Enter the index to read from the buffer (or -1 to exit): ";
        std::cin >> index;
        if (index == -1) {
            break;
        }
        if (index < 0 || index >= bufferSize) {
            std::cout << "Invalid index" << std::endl;
        } else {
            std::cout << "Buffer[" << index << "] = " << buffer[index] << std::endl;
        }
    }
    delete[] buffer;
    return 0;
}