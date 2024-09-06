#include <iostream>
#include <algorithm>

int getSum(int a, int b) {
    int sum = 0;
    for (int i = std::min(a, b); i <= std::max(a, b); i++) {
        sum += i;
    }
    return sum;
}