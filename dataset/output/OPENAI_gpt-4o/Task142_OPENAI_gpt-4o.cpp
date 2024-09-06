#include <iostream>

extern "C" {
    int gcd(int a, int b);
}

int main() {
    int a, b;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << "Greatest Common Divisor: " << gcd(a, b) << std::endl;
    return 0;
}

extern "C" int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}