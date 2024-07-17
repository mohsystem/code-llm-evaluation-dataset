#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];

    printf("Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);

    if (strlen(input) > BUFFER_SIZE) {
        printf("Input is too long for the buffer.
");
    } else {
        strcpy(buffer, input);
        printf("Input stored in buffer: %s
", buffer);
    }

    return 0;
}