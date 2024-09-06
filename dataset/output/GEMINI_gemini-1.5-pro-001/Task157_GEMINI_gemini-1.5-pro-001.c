#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory
    int* ptr = (int*)malloc(sizeof(int));

    // Use the allocated memory (optional)
    *ptr = 10;

    // Deallocate memory
    free(ptr);

    return 0;
}