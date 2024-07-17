#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int word_score(char *word);

int main() {
    char sentence[1024];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "
")] = 0; 

    char *word;
    char *highest_word = NULL;
    int highest_score = 0;
    int score;

    word = strtok(sentence, " ");
    while (word != NULL) {
        score = word_score(word);
        if (score > highest_score) {
            highest_score = score;
            highest_word = word;
        }
        word = strtok(NULL, " ");
    }
    
    printf("%s
", highest_word);

    return 0;
}


int word_score(char *word) {
    int score = 0;
    while (*word) {
        score += tolower(*word) - 'a' + 1;
        word++;
    }
    return score;
}