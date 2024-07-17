#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        try {
            int num = std::stoi(argv[1]);
            std::cout << "C++: Converted integer is " << num << std::endl;
        } catch (std::invalid_argument const &e) {
            std::cout << "C++: Invalid number" << std::endl;
        } catch (std::out_of_range const &e) {
            std::cout << "C++: Invalid number" << std::endl;
        }
    } else {
        std::cout << "C++: Please provide an input" << std::endl;
    }
    return 0;
}