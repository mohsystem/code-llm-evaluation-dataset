
#include <iostream>
#include <stdexcept>

int main() {
    const int bufferSize = 100;
    char* buffer = new char[bufferSize];
    
    // Fill buffer with some data
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = \'A\' + (i % 26);
    }
    
    while (true) {
        int index;
        std::cout << "Enter an index to read (0-99), or -1 to exit: ";
        try {
            std::cin >> index;
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input");
            }
            if (index == -1) {
                break;
            }
            if (index >= 0 && index < bufferSize) {
                std::cout << "Data at index " << index << ": " << buffer[index] << std::endl;
            } else {
                std::cout << "Invalid index. Please enter a number between 0 and 99." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << ". Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), \'\
\');
        }
    }
    
    std::cout << "Program terminated." << std::endl;
    delete[] buffer;
    return 0;
}
