#include <iostream>
#include <limits>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    if(!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter an integer.
";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
    } else {
        std::cout << "You entered: " << num << std::endl;
    }
    return 0;
}