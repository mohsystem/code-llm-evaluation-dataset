#include <stdio.h>

int find(int integers[], int size) {
    int even = 0, odd = 0, evenCount = 0, oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (integers[i] % 2 == 0) {
            even = integers[i];
            evenCount++;
        } else {
            odd = integers[i];
            oddCount++;
        }
    }
    return evenCount == 1 ? even : odd;
}