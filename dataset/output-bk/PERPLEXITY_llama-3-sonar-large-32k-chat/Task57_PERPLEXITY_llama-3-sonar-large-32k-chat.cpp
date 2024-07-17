#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    long long factorial = 1;
    for(int i = 1; i <= num; i++) {
        factorial *= i;
    }
    std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    return 0;
}