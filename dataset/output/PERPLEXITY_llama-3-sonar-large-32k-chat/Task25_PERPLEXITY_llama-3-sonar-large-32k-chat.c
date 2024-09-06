#include <stdio.h>

void number_lines(char* lines[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

int main() {
    char* lines[] = {"a", "b", "c"};
    int size = sizeof(lines) / sizeof(lines[0]);
    number_lines(lines, size);
    return 0;
}