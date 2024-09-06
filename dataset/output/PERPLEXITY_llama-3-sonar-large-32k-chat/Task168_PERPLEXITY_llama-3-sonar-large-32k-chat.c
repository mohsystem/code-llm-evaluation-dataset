#include <stdio.h>
#include <string.h>

void tweakLetters(char* s, int tweaks[], char* result) {
    for (int i = 0; i < strlen(s); i++) {
        result[i] = s[i] + tweaks[i];
    }
    result[strlen(s)] = '\0';
}

int main() {
    char result[100];
    tweakLetters("apple", (int[]){0, 1, -1, 0, -1}, result);
    printf("%s\n", result); // "aqold"
    tweakLetters("many", (int[]){0, 0, 0, -1}, result);
    printf("%s\n", result); // "manx"
    tweakLetters("rhino", (int[]){1, 1, 1, 1, 1}, result);
    printf("%s\n", result); // "sijop"
    return 0;
}