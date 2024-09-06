#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *int_ptr = (int *)malloc(sizeof(int));
    *int_ptr = 10;
    printf("Value at allocated memory: %d\n", *int_ptr);

    // Deallocate memory
    free(int_ptr);

    return 0;
}