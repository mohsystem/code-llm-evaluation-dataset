#include <iostream>
using namespace std;

int getSum(int a, int b) {
    if (a == b) {
        return a;
    } else {
        int sum = 0;
        for (int i = min(a, b); i <= max(a, b); i++) {
            sum += i;
        }
        return sum;
    }
}