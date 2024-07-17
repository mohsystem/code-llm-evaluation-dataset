#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    // Simulate some processing time
    for (volatile int i = 0; i < 100000000; i++);
    clock_t end = clock();
    double cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time in seconds (C): %f
", cpu_time);
    return 0;
}