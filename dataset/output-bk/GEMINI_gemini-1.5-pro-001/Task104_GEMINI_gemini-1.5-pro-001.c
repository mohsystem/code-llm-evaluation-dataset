#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    char input[100];

    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Buffer contents: %s
", buffer);
    return 0;
}