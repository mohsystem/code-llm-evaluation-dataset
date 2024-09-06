#include <stdio.h>
int find_outlier(int *integers, int length) {
    int evens = 0, odds = 0, even = 0, odd = 0;
    for (int i = 0; i < length; i++) {
        if (integers[i] % 2 == 0) {
            evens++;
            even = integers[i];
        } else {
            odds++;
            odd = integers[i];
        }
    }
    return evens < odds ? even : odd;
}