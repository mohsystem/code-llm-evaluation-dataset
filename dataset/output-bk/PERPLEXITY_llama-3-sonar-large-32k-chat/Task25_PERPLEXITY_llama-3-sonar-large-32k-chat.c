#include <stdio.h>
#include <string.h>

void numberLines(char* lines[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %s
", i + 1, lines[i]);
    }
}

int main() {
    char* lines[] = {"a", "b", "c"};
    int size = sizeof(lines) / sizeof(lines[0]);
    numberLines(lines, size);
    return 0;
}