#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int queueTime(int customers[], int size, int n) {
    int *tills = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < size; i++) {
        qsort(tills, n, sizeof(int), cmpfunc);
        tills[0] += customers[i];
    }
    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        if (tills[i] > totalTime) {
            totalTime = tills[i];
        }
    }
    free(tills);
    return totalTime;
}

int main() {
    int customers1[] = {5, 3, 4};
    printf("%d
", queueTime(customers1, 3, 1)); // should return 12

    int customers2[] = {10, 2, 3, 3};
    printf("%d
", queueTime(customers2, 4, 2)); // should return 10

    int customers3[] = {2, 3, 10};
    printf("%d
", queueTime(customers3, 3, 2)); // should return 12
    
    return 0;
}