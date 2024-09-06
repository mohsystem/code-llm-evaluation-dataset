#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* high_scoring_word(char* input_string) {
    char* word = strtok(input_string, " ");
    char* max_word = NULL;
    int max_score = 0;

    while (word != NULL) {
        int score = 0;
        for (int i = 0; word[i]; i++) {
            score += word[i] - 'a' + 1;
        }
        if (score > max_score) {
            max_score = score;
            max_word = word;
        }
        word = strtok(NULL, " ");
    }

    return max_word;
}