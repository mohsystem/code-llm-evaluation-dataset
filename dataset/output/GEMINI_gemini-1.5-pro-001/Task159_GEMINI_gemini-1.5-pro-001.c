#include <stdio.h>
#include <stdlib.h>

int main() {
    int bufferSize;

    printf("Enter the buffer size: ");
    if (scanf("%d", &bufferSize) != 1 || bufferSize <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.
");
        return 1;
    }

    int *buffer = (int *)malloc(bufferSize * sizeof(int));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.
");
        return 1;
    }

    for (int i = 0; i < bufferSize; ++i) {
        printf("Enter data for index %d: ", i);
        if (scanf("%d", &buffer[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.
");
            free(buffer);
            return 1;
        }
    }

    while (1) {
        int index;
        printf("Enter an index to read (or -1 to exit): ");
        if (scanf("%d", &index) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.
");
            continue;
        }

        if (index == -1) {
            break;
        }

        if (index >= 0 && index < bufferSize) {
            printf("Data at index %d: %d
", index, buffer[index]);
        } else {
            printf("Index out of range.
");
        }
    }

    free(buffer);

    return 0;
}