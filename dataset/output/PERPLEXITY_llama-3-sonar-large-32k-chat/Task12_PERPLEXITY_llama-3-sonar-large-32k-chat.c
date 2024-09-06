#include <stdio.h>
#include <string.h>

char* high(const char* s) {
    static char maxWord[100];
    int maxScore = 0;
    char* token = strtok((char*)s, " ");
    while (token != NULL) {
        int score = 0;
        for (int i = 0; i < strlen(token); i++) {
            score += token[i] - 96;
        }
        if (score > maxScore) {
            maxScore = score;
            strcpy(maxWord, token);
        }
        token = strtok(NULL, " ");
    }
    return maxWord;
}