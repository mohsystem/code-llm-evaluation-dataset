#include <stdio.h>
#include <time.h>

int main() {
    clock_t startTime = clock();
    double secondsElapsed = (double) (clock() - startTime) / CLOCKS_PER_SEC;
    printf("%f
", secondsElapsed);
    return 0;
}