#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer between 1 and 10
    int randomInteger = rand() % 10 + 1;
    printf("Random Integer: %d\n", randomInteger);

    // Generate a random floating-point number between 0 and 1
    double randomDouble = (double)rand() / RAND_MAX;
    printf("Random Double: %f\n", randomDouble);

    // Generate a random element from an array
    char *fruits[] = {"apple", "banana", "cherry"};
    int randomIndex = rand() % 3;
    char *randomFruit = fruits[randomIndex];
    printf("Random Fruit: %s\n", randomFruit);

    return 0;
}