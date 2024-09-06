#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char choice[10];

    printf("Enter your destination (A, B, or C): ");
    scanf("%s", choice);

    for (int i = 0; choice[i]; i++) {
        choice[i] = toupper(choice[i]);
    }

    if (strcmp(choice, "A") == 0) {
        printf("Redirecting to page A...\n");
    } else if (strcmp(choice, "B") == 0) {
        printf("Redirecting to page B...\n");
    } else if (strcmp(choice, "C") == 0) {
        printf("Redirecting to page C...\n");
    } else {
        printf("Invalid choice. Please enter A, B, or C.\n");
    }

    return 0;
}