
#include <iostream>
#include <string>
#include <stdexcept>

int convertToInt(const std::string& input) {
    try {
        return std::stoi(input);
    } catch (const std::invalid_argument& e) {
        return -1;
    } catch (const std::out_of_range& e) {
        return -1;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    int result = convertToInt(input);

    if (result != -1) {
        std::cout << "Converted integer: " << result << std::endl;
    } else {
        std::cout << "Invalid input: Cannot convert to integer" << std::endl;
    }

    return 0;
}
