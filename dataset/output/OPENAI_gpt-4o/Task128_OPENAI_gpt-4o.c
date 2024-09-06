#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    printf("C Random Number: %d\n", rand() % 100 + 1);
    return 0;
}