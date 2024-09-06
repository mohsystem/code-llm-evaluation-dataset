#include <stdio.h>

int getSum(int a, int b) {
    if (a == b) {
        return a;
    } else {
        int sum = 0;
        for (int i = (a < b ? a : b); i <= (a > b ? a : b); i++) {
            sum += i;
        }
        return sum;
    }
}