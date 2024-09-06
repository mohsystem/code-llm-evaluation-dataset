#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("That's not a valid number!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    } else {
        printf("You entered: %d\n", num);
    }
    return 0;
}