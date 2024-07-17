#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    char input[100];

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &num) != 1) {
        printf("Error: Invalid input. Please enter a number.
");
        return 1;
    }

    printf("You entered: %d
", num);
    // Perform operations with num here

    return 0;
}