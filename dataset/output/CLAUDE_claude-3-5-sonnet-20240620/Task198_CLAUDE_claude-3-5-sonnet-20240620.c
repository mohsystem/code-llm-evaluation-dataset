
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (1) {
        int result = (rand7() - 1) * 7 + (rand7() - 1);
        if (result < 40) {
            return result % 10 + 1;
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of times to call rand10(): ");
    scanf("%d", &n);
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = rand10();
    }
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(",");
    }
    printf("]\
");
    free(result);
    return 0;
}
