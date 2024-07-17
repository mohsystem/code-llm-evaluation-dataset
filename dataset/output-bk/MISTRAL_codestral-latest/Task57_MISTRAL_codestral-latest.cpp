#include <iostream>

int main() {
    int num;
    long factorial = 1;

    std::cout << "Enter a number: ";
    std::cin >> num;

    for(int i = 1; i <= num; ++i) {
        factorial *= i;
    }

    std::cout << "Factorial of " << num << " = " << factorial;

    return 0;
}