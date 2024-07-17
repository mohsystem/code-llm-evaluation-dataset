#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *myVar = (int *)malloc(sizeof(int));
    if (myVar == NULL) {
        fprintf(stderr, "Memory allocation failed
");
        return 1;
    }
    *myVar = 42;
    printf("C: Value = %d
", *myVar);

    // Deallocate memory
    free(myVar);

    return 0;
}