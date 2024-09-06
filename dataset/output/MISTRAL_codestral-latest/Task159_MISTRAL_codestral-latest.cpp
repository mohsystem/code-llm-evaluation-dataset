// C++
#include <iostream>
#include <fstream>

int main() {
    // Allocate memory buffer
    std::ofstream outfile("buffer.dat", std::ios::binary);
    char zero = 0;
    for (int i = 0; i < 1024; i++) {
        outfile.write(&zero, sizeof(zero));
    }
    outfile.close();

    // User input for index
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;

    // Read from buffer
    std::ifstream infile("buffer.dat", std::ios::binary);
    infile.seekg(index);
    char value;
    infile.read(&value, sizeof(value));
    infile.close();

    std::cout << "Value at index: " << static_cast<int>(value) << std::endl;

    return 0;
}