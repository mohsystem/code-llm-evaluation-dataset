// C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int match(char* word, char* guess, int matches) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess[i]) {
            count++;
        }
    }
    return count == matches;
}

void findSecretWord(char** words, int wordsSize, Master* master) {
    for (int i = 0; i < 10; i++) {
        int guessIndex = rand() % wordsSize;
        char* guess = words[guessIndex];
        int matches = master->guess(guess);
        if (matches == 6) {
            printf("You guessed the secret word correctly.
");
            return;
        }
        char** newWords = malloc(wordsSize * sizeof(char*));
        int newWordsSize = 0;
        for (int j = 0; j < wordsSize; j++) {
            if (match(words[j], guess, matches)) {
                newWords[newWordsSize++] = words[j];
            }
        }
        words = newWords;
        wordsSize = newWordsSize;
    }
    printf("Either you took too many guesses, or you did not find the secret word.
");
}