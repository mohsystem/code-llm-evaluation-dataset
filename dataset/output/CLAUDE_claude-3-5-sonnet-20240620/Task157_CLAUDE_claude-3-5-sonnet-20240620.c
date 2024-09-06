
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory
    int* ptr = (int*)malloc(10 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed\\n");
        return 1;
    }

    // Use the memory
    ptr[0] = 5;
    printf("%d\\n", ptr[0]);

    // Deallocate memory
    free(ptr);

    return 0;
}
