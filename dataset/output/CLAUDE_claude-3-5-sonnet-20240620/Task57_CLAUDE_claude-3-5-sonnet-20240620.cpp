
#include <iostream>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    long long result = factorial(num);
    std::cout << "The factorial of " << num << " is " << result << std::endl;
    return 0;
}
