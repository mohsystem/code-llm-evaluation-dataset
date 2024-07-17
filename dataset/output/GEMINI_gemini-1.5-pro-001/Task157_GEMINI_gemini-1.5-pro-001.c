#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory
    int* array = (int*)malloc(1024 * sizeof(int));

    // Use memory (example)
    if (array != NULL) {
        array[0] = 10;
    }

    // Deallocate memory
    free(array);

    return 0;
}