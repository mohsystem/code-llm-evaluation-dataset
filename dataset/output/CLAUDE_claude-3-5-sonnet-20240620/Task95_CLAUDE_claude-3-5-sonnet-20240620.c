
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\\n", cpu_time_used);
    return 0;
}
