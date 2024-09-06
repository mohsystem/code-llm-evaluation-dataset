#include <stdio.h>
#include <string.h>

int main() {
    char input[1024];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove potential newline character
        input[strcspn(input, "\n")] = 0;
        // Process the string safely here
        printf("%s\n", input);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}