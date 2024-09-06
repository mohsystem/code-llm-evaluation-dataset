
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int bufferSize = 100;
    char* buffer = (char*)malloc(bufferSize * sizeof(char));

    if (buffer == NULL) {
        printf("Memory allocation failed\\n");
        return 1;
    }

    // Initialize buffer with some data
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 'A' + (i % 26);
    }

    while (1) {
        int index;
        printf("Enter an index to read (0-99), or -1 to exit: ");
        if (scanf("%d", &index) != 1) {
            printf("Invalid input. Please enter a valid integer.\\n");
            while (getchar() != '\\n'); // Clear input buffer
            continue;
        }

        if (index == -1) {
            break;
        }

        if (index >= 0 && index < bufferSize) {
            printf("Data at index %d: %c\\n", index, buffer[index]);
        } else {
            printf("Invalid index. Please enter a number between 0 and 99.\\n");
        }
    }

    free(buffer); // Free the allocated memory
    return 0;
}
