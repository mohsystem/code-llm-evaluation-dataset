#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encryptString(char* inputString, int key) {
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (isalpha(inputString[i])) {
            int asciiOffset = isupper(inputString[i]) ? 65 : 97;
            inputString[i] = (inputString[i] - asciiOffset + key) % 26 + asciiOffset;
        }
    }
}

int main() {
    char inputString[] = "HELLO WORLD";
    int key = 3;
    encryptString(inputString, key);
    printf("%s\n", inputString);
    return 0;
}