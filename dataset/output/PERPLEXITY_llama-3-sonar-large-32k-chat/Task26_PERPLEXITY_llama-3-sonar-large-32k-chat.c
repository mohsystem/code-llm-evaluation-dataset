#include <stdio.h>

int findOdd(int seq[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (seq[i] == seq[j]) {
                count++;
            }
        }
        if (count % 2 != 0) {
            result = seq[i];
        }
    }
    return result;
}

int main() {
    int seq[] = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    int n = sizeof(seq) / sizeof(seq[0]);
    int result = findOdd(seq, n);
    printf("%d
", result);
    return 0;
}