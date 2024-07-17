#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() {
    return rand() % 100 + 1;
}

int main() {
    srand(time(0));
    printf("C random number: %d
", generateRandomNumber());
    return 0;
}