
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 6

int match(const char* a, const char* b) {
    int matches = 0;
    for (int i = 0; i < WORD_LENGTH; ++i)
        if (a[i] == b[i])
            matches++;
    return matches;
}

void findSecretWord(char words[MAX_WORDS][WORD_LENGTH + 1], int wordCount, int (*master_guess)(const char*)) {
    srand(time(NULL));
    for (int i = 0, n = 0; i < 10 && n < 6; ++i) {
        int guessIndex = rand() % wordCount;
        n = master_guess(words[guessIndex]);
        
        char candidates[MAX_WORDS][WORD_LENGTH + 1];
        int candidateCount = 0;
        
        for (int j = 0; j < wordCount; ++j) {
            if (match(words[guessIndex], words[j]) == n) {
                strcpy(candidates[candidateCount++], words[j]);
            }
        }
        
        memcpy(words, candidates, candidateCount * sizeof(words[0]));
        wordCount = candidateCount;
    }
}
