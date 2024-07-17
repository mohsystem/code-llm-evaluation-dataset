#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 10;
    char* buffer = (char*)malloc(size * sizeof(char));

    // Fill the buffer with some data
    for (int i = 0; i < size; i++) {
        buffer[i] = 'A' + i;
    }

    int index;
    // Allow the user to read data from the buffer
    while (1) {
        printf("Enter index to read (0-%d) or -1 to exit: ", size-1);
        scanf("%d", &index);

        if (index == -1) {
            break;
        }

        if (index >= 0 && index < size) {
            printf("Data at index %d: %c
", index, buffer[index]);
        } else {
            printf("Index out of bounds
");
        }
    }

    free(buffer);
    return 0;
}