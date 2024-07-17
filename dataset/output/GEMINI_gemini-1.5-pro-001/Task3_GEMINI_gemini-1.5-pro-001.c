#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPangram(const char *text) {
    if (strlen(text) < 26) {
        return false;
    }

    int foundLetters[26] = {0};

    for (int i = 0; text[i] != '\0'; i++) {
        char c = tolower((unsigned char)text[i]);
        if (c >= 'a' && c <= 'z') {
            foundLetters[c - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!foundLetters[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog";
    if (isPangram(text)) {
        printf("True
");
    } else {
        printf("False
");
    }
    return 0;
}