#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size, index;

    printf("Enter the size of the buffer: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    char **buffer = (char **)malloc(size * sizeof(char *));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        buffer[i] = (char *)malloc(100 * sizeof(char)); // Assuming max data size is 99 characters
        if (buffer[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
        printf("Enter data for index %d: ", i);
        scanf(" %[^\n]", buffer[i]); 
    }

    while (1) {
        printf("Enter an index to read data (or -1 to exit): ");
        if (scanf("%d", &index) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if (index == -1) {
            break;
        } else if (index >= 0 && index < size) {
            printf("Data at index %d: %s\n", index, buffer[index]);
        } else {
            printf("Index out of range.\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(buffer[i]);
    }
    free(buffer);

    return 0;
}