#include <stdio.h>
#include <stdlib.h>

int find_outlier(int *integers, int count) {
    int parity = integers[0] % 2 + integers[1] % 2 + integers[2] % 2;
    if (parity < 2) {
        for (int i = 0; i < count; i++) {
            if (integers[i] % 2 != 0) {
                return integers[i];
            }
        }
    } else {
        for (int i = 0; i < count; i++) {
            if (integers[i] % 2 == 0) {
                return integers[i];
            }
        }
    }
    return 0;
}