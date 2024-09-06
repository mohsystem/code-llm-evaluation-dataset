#include <stdio.h>
#include <stdlib.h>

int main() {
    int cNum;
    printf("Enter a number for C: ");
    if (scanf("%d", &cNum) != 1) {
        printf("Invalid input in C\n");
        while((cNum = getchar()) != EOF && cNum != '\n');
    } else {
        printf("C read the number: %d\n", cNum);
    }
    
    return 0;
}