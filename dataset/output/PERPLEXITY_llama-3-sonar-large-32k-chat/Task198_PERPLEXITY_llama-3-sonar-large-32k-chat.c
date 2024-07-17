#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (true) {
        int num = (rand7() - 1) * 7 + rand7();
        if (num <= 40) {
            return num % 10 + 1;
        }
    }
}

int main() {
    srand(time(0));
    int n = 1;  // change this to test with different inputs
    for (int i = 0; i < n; i++) {
        printf("%d ", rand10());
    }
    return 0;
}