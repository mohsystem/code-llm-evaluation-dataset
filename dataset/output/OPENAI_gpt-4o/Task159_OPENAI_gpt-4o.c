// C code

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Enter the size of the buffer: ");
    scanf("%d", &size);
    int *buffer = (int*)malloc(size * sizeof(int));
    
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        int idx;
        printf("Enter index (-1 to quit): ");
        scanf("%d", &idx);
        if (idx == -1) break;

        if (idx >= 0 && idx < size) {
            printf("Value at index %d: %d\n", idx, buffer[idx]);
        } else {
            printf("Index out of bounds.\n");
        }
    }

    free(buffer);
    return 0;
}