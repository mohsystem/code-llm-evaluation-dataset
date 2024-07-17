// C
#include <stdio.h>
#define MAX_SIZE 100 // Define a maximum size for the input

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    printf("You entered: %s", input);
    return 0;
}