#include <iostream>

long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    std::cout << "Enter a number:" << std::endl;
    std::cin >> number;
    std::cout << "Factorial: " << factorial(number) << std::endl;
    return 0;
}