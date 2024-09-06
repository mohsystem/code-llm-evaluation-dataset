#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    printf("%d\n", randomNumber);
    return 0;
}