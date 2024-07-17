
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 20

int main() {
    char buffer[BUFFER_SIZE];
    char input[100];

    printf("Enter a string (max %d characters):\
", BUFFER_SIZE);
    fgets(input, sizeof(input), stdin);

    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == \'\
\') {
        input[--input_length] = \'\\0\';
    }

    size_t length = (input_length < BUFFER_SIZE) ? input_length : BUFFER_SIZE;
    strncpy(buffer, input, length);

    printf("Buffer contents:\
");
    printf("%.*s\
", (int)length, buffer);

    return 0;
}
