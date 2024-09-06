#include <time.h>
#include <stdio.h>

int main() {
    clock_t start = clock();
    double seconds = (double)start / CLOCKS_PER_SEC;
    printf("Current processor time in seconds: %f\n", seconds);
    return 0;
}