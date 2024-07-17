#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Enter an integer: ");
    if(scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.
");
        return 1;
    }
    printf("You entered: %d
", num);
    return 0;
}