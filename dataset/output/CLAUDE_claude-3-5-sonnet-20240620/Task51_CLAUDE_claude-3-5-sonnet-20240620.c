
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != \'\\0\'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? \'A\' : \'a\';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

int main() {
    char text[100];
    int shift;

    printf("Enter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\
")] = \'\\0\';  // Remove newline

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    encrypt(text, shift);
    printf("Encrypted string: %s\
", text);

    return 0;
}
