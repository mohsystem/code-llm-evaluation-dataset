#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (1) {
        int num = (rand7() - 1) * 7 + rand7(); // Generate a number between 1 and 49
        if (num <= 40) {
            return (num - 1) % 10 + 1; // Map to 1-10
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int n;
    printf("Enter the number of times to call rand10(): ");
    scanf("%d", &n);

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", rand10());
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}