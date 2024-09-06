#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        return 1;
    }

    char* end;
    long num = std::strtol(argv[1], &end, 10);

    if (*end != '\0') {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
    } else {
        std::cout << num << std::endl;
    }

    return 0;
}