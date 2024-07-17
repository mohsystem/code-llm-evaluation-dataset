#include <iostream>
#include <limits>

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (std::cin.fail()) {
        std::cout << "Error: Invalid input. Please enter a number.
";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
        return 1;
    }

    std::cout << "You entered: " << num << std::endl;
    // Perform operations with num here

    return 0;
}