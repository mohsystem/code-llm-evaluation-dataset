
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\\0'; ++i) {
        if (isalpha(text[i])) {
            char asciiOffset = isupper(text[i]) ? 65 : 97;
            text[i] = ((text[i] - asciiOffset + shift) % 26) + asciiOffset;
        }
    }
}

int main() {
    char text[1000];
    int shift;
    
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\\n")] = 0;  // Remove newline
    
    printf("Enter shift value: ");
    scanf("%d", &shift);
    
    encrypt(text, shift);
    printf("Encrypted text: %s\\n", text);
    
    return 0;
}
