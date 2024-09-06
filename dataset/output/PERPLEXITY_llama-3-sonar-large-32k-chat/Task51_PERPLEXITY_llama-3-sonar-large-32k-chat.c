#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* encrypt(const char* text, int shift) {
    static char result[256];
    int i = 0;

    for (; *text; text++) {
        if (isalpha(*text)) {
            char base = isupper(*text) ? 'A' : 'a';
            result[i++] = (char) ((*text - base + shift) % 26 + base);
        } else {
            result[i++] = *text;
        }
    }

    result[i] = '\0';
    return result;
}

int main() {
    const char* text = "Hello, World!";
    int shift = 3;
    printf("Text : %s\n", text);
    printf("Shift : %d\n", shift);
    printf("Cipher: %s\n", encrypt(text, shift));
    return 0;
}