#include <stdio.h>

int find_it(int seq[], int len) {
    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (seq[i] == seq[j]) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return seq[i];
        }
    }
    return -1;
}