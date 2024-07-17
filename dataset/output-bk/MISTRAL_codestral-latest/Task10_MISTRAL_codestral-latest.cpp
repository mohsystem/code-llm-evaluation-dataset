#include <iostream>

int getSum(int a, int b) {
    if (a == b) {
        return a;
    } else if (a < b) {
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += i;
        }
        return sum;
    } else {
        int sum = 0;
        for (int i = b; i <= a; i++) {
            sum += i;
        }
        return sum;
    }
}

int main() {
    std::cout << getSum(1, 0) << std::endl; // Output: 1
    std::cout << getSum(1, 2) << std::endl; // Output: 3
    std::cout << getSum(0, 1) << std::endl; // Output: 1
    std::cout << getSum(1, 1) << std::endl; // Output: 1
    std::cout << getSum(-1, 0) << std::endl; // Output: -1
    std::cout << getSum(-1, 2) << std::endl; // Output: 2
    return 0;
}