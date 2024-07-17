#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[] = {2, 2, 1, 2, 1};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    if (length == 0) {
        printf("[]
"); // Print an empty array if the input is empty
        return 0;
    }

    // Find the index of the smallest element
    int minIndex = 0;
    for (int i = 1; i < length; i++) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }
    }

    // Print the array without the smallest element
    printf("[");
    for (int i = 0; i < length; i++) {
        if (i != minIndex) {
            printf("%d", numbers[i]);
            if (i != length - 1 && i != minIndex) {
                printf(",");
            }
        }
    }
    printf("]
");

    return 0;
}