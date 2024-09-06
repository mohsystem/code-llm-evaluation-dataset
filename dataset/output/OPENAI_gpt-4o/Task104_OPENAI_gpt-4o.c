#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];
int buffer_index = 0;

void add_char(char c) {
    if (buffer_index < BUFFER_SIZE) {
        buffer[buffer_index++] = c;
    } else {
        printf("Buffer is full.\n");
    }
}

void print_buffer() {
    for (int i = 0; i < buffer_index; ++i) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter characters to fill the buffer:\n");
    while (buffer_index < BUFFER_SIZE) {
        printf("Enter a character: ");
        char ch;
        scanf(" %c", &ch);
        add_char(ch);
    }

    printf("Buffer contents:\n");
    print_buffer();

    return 0;
}