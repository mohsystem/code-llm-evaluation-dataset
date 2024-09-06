#include <string.h>
#include <stdlib.h>
char* tweakLetters(char* word, int* tweaks) {
    char* result = malloc(strlen(word) + 1);
    for (int i = 0; i < strlen(word); i++) {
        result[i] = word[i] + tweaks[i];
    }
    result[strlen(word)] = '\0';
    return result;
}