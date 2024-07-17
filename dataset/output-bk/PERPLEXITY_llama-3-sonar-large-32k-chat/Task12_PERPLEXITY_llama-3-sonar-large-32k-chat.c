#include <stdio.h>
#include <string.h>

int score(char *word) {
    int score = 0;
    for (; *word; word++) {
        score += *word - 'a' + 1;
    }
    return score;
}

char *high(const char *s) {
    char *maxWord = strtok((char *)s, " ");
    int maxScore = score(maxWord);
    char *word;
    while ((word = strtok(NULL, " ")) != NULL) {
        int score = score(word);
        if (score > maxScore) {
            maxScore = score;
            maxWord = word;
        }
    }
    return maxWord;
}