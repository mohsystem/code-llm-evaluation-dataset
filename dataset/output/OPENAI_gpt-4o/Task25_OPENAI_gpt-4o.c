#include <stdio.h>
#include <string.h>

void number(char lines[][100], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %s
", i + 1, lines[i]);
    }
}

int main() {
    char lines[][100] = {"a", "b", "c"};
    int size = sizeof(lines)/sizeof(lines[0]);
    number(lines, size);
    return 0;
}