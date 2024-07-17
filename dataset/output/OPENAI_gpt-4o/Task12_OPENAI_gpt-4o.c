#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wordScore(const char *word) {
    int score = 0;
    while (*word) {
        score += *word - 'a' + 1;
        word++;
    }
    return score;
}

char* highestScoringWord(const char *str) {
    char *result = NULL, *token, *copy = strdup(str), *saveptr;
    int highestScore = 0;

    token = strtok_r(copy, " ", &saveptr);
    while (token) {
        int score = wordScore(token);
        if (score > highestScore) {
            highestScore = score;
            result = token;
        }
        token = strtok_r(NULL, " ", &saveptr);
    }

    free(copy);
    return result;
}

int main() {
    const char str[] = "example input sentence";
    printf("%s
", highestScoringWord(str));
    return 0;
}