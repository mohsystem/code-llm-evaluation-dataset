#include <iostream>
#include <limits>

int main() {
    int num, num2;
    std::cout << "Enter a number: ";
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter a valid number.
";
        std::cout << "Enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
    }
    std::cout << "You entered: " << num << std::endl;
    std::cout << "Enter another number: ";
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter a valid number.
";
        std::cout << "Enter another number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '
');
    }
    std::cout << "You entered: " << num2 << std::endl;
    if (num2 == 0) {
        std::cout << "Cannot divide by zero.
";
        return 1;
    }
    int result = num / num2;
    std::cout << "Result: " << result << std::endl;
    return 0;
}