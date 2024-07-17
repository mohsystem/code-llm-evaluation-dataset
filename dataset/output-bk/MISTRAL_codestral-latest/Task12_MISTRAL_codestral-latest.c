#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *high(const char *s) {
    char *token, *str, *maxWord = NULL;
    int maxScore = 0;
    str = strdup(s);
    token = strtok(str, " ");
    while (token != NULL) {
        int score = 0;
        for (int i = 0; i < strlen(token); i++) {
            score += token[i] - 'a' + 1;
        }
        if (score > maxScore) {
            maxScore = score;
            maxWord = token;
        }
        token = strtok(NULL, " ");
    }
    free(str);
    return maxWord;
}