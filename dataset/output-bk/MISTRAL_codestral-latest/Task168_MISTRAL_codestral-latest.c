#include <stdio.h>
#include <string.h>

void tweakLetters(char* word, int* tweaks, char* result) {
    for (int i = 0; i < strlen(word); i++) {
        char c = ((word[i] - 'a' + tweaks[i]) % 26) + 'a';
        result[i] = c;
    }
    result[strlen(word)] = '\0';
}