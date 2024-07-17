#include <iostream>

int sumBetween(int a, int b) {
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    int sum = 0;
    for (int i = min; i <= max; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    std::cout << sumBetween(-1, 2) << std::endl;
    return 0;
}