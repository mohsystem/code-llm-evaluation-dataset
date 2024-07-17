#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    printf("Enter a string: ");
    fgets(buffer, 10, stdin);
    buffer[strcspn(buffer, "
")] = 0; // remove newline character
    printf("Buffer contents: %s
", buffer);
    return 0;
}