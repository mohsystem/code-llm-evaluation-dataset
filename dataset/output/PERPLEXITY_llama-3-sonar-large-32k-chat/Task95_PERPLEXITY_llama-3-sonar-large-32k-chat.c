#include <time.h>

int main() {
    clock_t start_time = clock();
    printf("Current processor time in seconds: %ld
", (long)start_time / CLOCKS_PER_SEC);
    return 0;
}