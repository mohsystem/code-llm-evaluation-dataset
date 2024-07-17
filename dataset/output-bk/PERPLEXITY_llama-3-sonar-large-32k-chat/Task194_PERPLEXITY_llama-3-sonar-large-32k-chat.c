#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findSecretWord(char **wordlist, int wordlistSize, Master *master) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        char *guess = wordlist[rand() % wordlistSize];
        int result = master->guess(guess);
        if (result == 6) return;
        int newSize = 0;
        for (int j = 0; j < wordlistSize; j++) {
            if (match(wordlist[j], guess) == result) {
                wordlist[newSize] = wordlist[j];
                newSize++;
            }
        }
        wordlistSize = newSize;
    }
}

int match(char *word1, char *word2) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (word1[i] == word2[i]) count++;
    }
    return count;
}