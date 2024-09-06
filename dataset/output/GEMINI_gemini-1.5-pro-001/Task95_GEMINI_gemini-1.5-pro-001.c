#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time = clock();
    // Some code here
    clock_t end_time = clock();
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f seconds\n", cpu_time_used);
    return 0;
}