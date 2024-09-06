#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* words[] = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
int wordsSize = 4;

typedef struct {
    char* secret;
    int guessCount;
} Master;

int guess(Master* master, char* word) {
    master->guessCount += 1;
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], word) == 0) {
            int matches = 0;
            for (int j = 0; j < strlen(master->secret); j++) {
                if (master->secret[j] == word[j]) {
                    matches++;
                }
            }
            return matches;
        }
    }
    return -1;
}

int matchCount(char* w1, char* w2) {
    int count = 0;
    for (int i = 0; i < strlen(w1); i++) {
        if (w1[i] == w2[i]) {
            count++;
        }
    }
    return count;
}

void findSecretWord(char* words[], int wordsSize, Master* master, int allowedGuesses) {
    srand(time(0));
    for (int i = 0; i < allowedGuesses; i++) {
        char* guessWord = words[rand() % wordsSize];
        int matches = guess(master, guessWord);
        if (matches == 6) {
            printf("You guessed the secret word correctly.\n");
            return;
        }
        char* newWords[wordsSize];
        int newWordsSize = 0;
        for (int j = 0; j < wordsSize; j++) {
            if (matchCount(words[j], guessWord) == matches) {
                newWords[newWordsSize++] = words[j];
            }
        }
        for (int j = 0; j < newWordsSize; j++) {
            words[j] = newWords[j];
        }
        wordsSize = newWordsSize;
    }
    printf("Either you took too many guesses, or you did not find the secret word.\n");
}

int main() {
    char* secret = "acckzz";
    int allowedGuesses = 10;
    Master master = {secret, 0};
    findSecretWord(words, wordsSize, &master, allowedGuesses);

    return 0;
}