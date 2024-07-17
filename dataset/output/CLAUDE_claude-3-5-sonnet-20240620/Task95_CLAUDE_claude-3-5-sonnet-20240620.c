
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    double cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("Current processor time: %.9f seconds\
", cpu_time_used);
    return 0;
}
