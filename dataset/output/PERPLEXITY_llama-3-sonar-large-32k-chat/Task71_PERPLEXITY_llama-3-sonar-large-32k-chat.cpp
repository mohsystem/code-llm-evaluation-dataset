#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No input provided. Please provide a command line argument." << std::endl;
        return 1;
    }
    try {
        int num = std::stoi(argv[1]);
        std::cout << "The integer value is: " << num << std::endl;
    } catch (std::invalid_argument const &e) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    } catch (std::out_of_range const &e) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    }
    return 0;
}