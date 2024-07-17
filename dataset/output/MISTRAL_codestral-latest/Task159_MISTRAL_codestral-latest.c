#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the size of the buffer: ");
    scanf("%d", &size);
    int* buffer = (int*)malloc(size * sizeof(int));

    int index;
    printf("Enter the index to read from the buffer: ");
    scanf("%d", &index);

    if (index >= 0 && index < size) {
        printf("Value at index %d: %d
", index, buffer[index]);
    } else {
        printf("Invalid index.
");
    }

    free(buffer);
    return 0;
}