
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 6

typedef struct {
    char* secret;
    int guesses;
} Master;

int guess(Master* master, const char* word) {
    master->guesses++;
    int matches = 0;
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (master->secret[i] == word[i]) {
            matches++;
        }
    }
    return matches;
}

int getMatches(const char* word1, const char* word2) {
    int matches = 0;
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (word1[i] == word2[i]) {
            matches++;
        }
    }
    return matches;
}

void findSecretWord(char words[MAX_WORDS][WORD_LENGTH + 1], int wordCount, Master* master) {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int index = rand() % wordCount;
        char* guessWord = words[index];
        int matches = guess(master, guessWord);
        if (matches == WORD_LENGTH) return;

        char newWords[MAX_WORDS][WORD_LENGTH + 1];
        int newWordCount = 0;

        for (int j = 0; j < wordCount; j++) {
            if (getMatches(words[j], guessWord) == matches) {
                strcpy(newWords[newWordCount++], words[j]);
            }
        }

        memcpy(words, newWords, sizeof(newWords));
        wordCount = newWordCount;
    }
}

int main() {
    char secret[] = "acckzz";
    char words[MAX_WORDS][WORD_LENGTH + 1] = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
    int wordCount = 4;

    Master master = {secret, 0};
    findSecretWord(words, wordCount, &master);

    printf("%s\\n", master.guesses <= 10 ? "You guessed the secret word correctly." : "Either you took too many guesses, or you did not find the secret word.");

    return 0;
}
