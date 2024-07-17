
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please provide a string argument." << std::endl;
        return 1;
    }
    
    std::string input = argv[1];
    try {
        int result = std::stoi(input);
        std::cout << "Converted integer: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input. Cannot convert to integer." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Input is out of range for integer conversion." << std::endl;
    }
    
    return 0;
}
