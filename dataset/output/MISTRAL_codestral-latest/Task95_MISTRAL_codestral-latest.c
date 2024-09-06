#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    // Your code here
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Processor time: %.6f seconds\n", duration);
    return 0;
}