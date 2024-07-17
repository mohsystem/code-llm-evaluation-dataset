#include <stdio.h>
#include <string.h>

int main() {
    char choice[2];
    printf("Enter your destination (A/B/C): ");
    scanf("%s", choice);

    if (strcmp(choice, "A") == 0 || strcmp(choice, "a") == 0) {
        printf("https://www.exampleA.com
");
    } else if (strcmp(choice, "B") == 0 || strcmp(choice, "b") == 0) {
        printf("https://www.exampleB.com
");
    } else if (strcmp(choice, "C") == 0 || strcmp(choice, "c") == 0) {
        printf("https://www.exampleC.com
");
    } else {
        printf("Invalid choice.
");
    }

    return 0;
}