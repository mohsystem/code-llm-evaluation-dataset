#include <iostream>

int main() {
    std::cout << "Enter the size of the buffer: ";
    int size;
    std::cin >> size;
    int* buffer = new int[size];

    std::cout << "Enter the index to read from the buffer: ";
    int index;
    std::cin >> index;

    if (index >= 0 && index < size) {
        std::cout << "Value at index " << index << ": " << buffer[index] << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }

    delete[] buffer;
    return 0;
}