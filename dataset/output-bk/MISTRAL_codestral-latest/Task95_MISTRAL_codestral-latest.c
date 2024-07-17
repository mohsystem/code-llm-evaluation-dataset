// C
#include <time.h>
#include <stdio.h>

int main() {
    clock_t start = clock();
    double time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Current processor time: %f seconds
", time_spent);
    return 0;
}