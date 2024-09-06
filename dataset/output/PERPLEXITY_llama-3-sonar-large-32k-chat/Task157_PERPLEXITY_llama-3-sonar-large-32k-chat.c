code here:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    printf("%d\n", *ptr);  // prints 10

    free(ptr);
    ptr = (int*)malloc(sizeof(int));
    *ptr = 20;
    printf("%d\n", *ptr);  // prints 20

    free(ptr);
    return 0;
}