#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (1) {
        int num = (rand7() - 1) * 7 + rand7();
        if (num <= 40) {
            return (num - 1) % 10 + 1;
        }
    }
}

int main() {
    srand((unsigned)time(0));
    int n;
    scanf("%d", &n);
    int results[n];
    for (int i = 0; i < n; i++) {
        results[i] = rand10();
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
    return 0;
}