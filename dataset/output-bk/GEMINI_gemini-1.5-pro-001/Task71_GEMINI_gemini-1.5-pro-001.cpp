#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please provide an argument." << std::endl;
        return 1;
    }

    try {
        int intValue = std::stoi(argv[1]);
        std::cout << "The integer value is: " << intValue << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << "Input out of range for an integer." << std::endl;
    }

    return 0;
}