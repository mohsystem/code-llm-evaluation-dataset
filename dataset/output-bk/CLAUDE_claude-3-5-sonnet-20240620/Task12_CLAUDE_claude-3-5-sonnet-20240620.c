
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int calculateScore(const char* word) {
    int score = 0;
    for (int i = 0; word[i] != \'\\0\'; i++) {
        score += tolower(word[i]) - \'a\' + 1;
    }
    return score;
}

int main() {
    char input[MAX_LENGTH];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\
")] = \'\\0\';

    char* token;
    char highestScoringWord[MAX_LENGTH] = "";
    int highestScore = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        int score = calculateScore(token);
        if (score > highestScore) {
            highestScore = score;
            strcpy(highestScoringWord, token);
        }
        token = strtok(NULL, " ");
    }

    printf("%s\
", highestScoringWord);

    return 0;
}
