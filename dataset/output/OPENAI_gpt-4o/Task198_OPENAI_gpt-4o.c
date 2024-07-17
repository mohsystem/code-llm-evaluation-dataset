#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (1) {
        int x = (rand7() - 1) * 7 + rand7();
        if (x <= 40) {
            return 1 + (x - 1) % 10;
        }
    }
}

int main() {
    srand(time(0));
    int n = 3;
    int result[n];
    for (int i = 0; i < n; ++i) {
        result[i] = rand10();
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i]);
    }
    printf("
");
    return 0;
}