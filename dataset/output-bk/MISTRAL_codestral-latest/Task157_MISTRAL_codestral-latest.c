// C
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory
    int size = 100;
    int* memory = (int*)malloc(size * sizeof(int));

    // Deallocate memory
    free(memory);

    return 0;
}