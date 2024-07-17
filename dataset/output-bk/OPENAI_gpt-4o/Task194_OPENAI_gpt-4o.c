#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char secret[7];
    int guess_count;
} Master;

int guess(Master* master, char word[7], char words[][7], int words_size) {
    master->guess_count++;
    int found = 0;
    for (int i = 0; i < words_size; i++) {
        if (strcmp(word, words[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        return -1;
    }
    int matches = 0;
    for (int i = 0; i < 6; i++) {
        if (master->secret[i] == word[i]) {
            matches++;
        }
    }
    return matches;
}

int match(char word1[7], char word2[7]) {
    int matches = 0;
    for (int i = 0; i < 6; i++) {
        if (word1[i] == word2[i]) {
            matches++;
        }
    }
    return matches;
}

void findSecretWord(char words[][7], int words_size, Master* master, int allowedGuesses) {
    int attempts = 0;
    srand(time(NULL));
    while (attempts < allowedGuesses) {
        char guess_word[7];
        strcpy(guess_word, words[rand() % words_size]);
        int matches = guess(master, guess_word, words, words_size);
        if (matches == 6) {
            printf("You guessed the secret word correctly.
");
            return;
        }
        char filtered_words[words_size][7];
        int count = 0;
        for (int i = 0; i < words_size; i++) {
            if (match(words[i], guess_word) == matches) {
                strcpy(filtered_words[count++], words[i]);
            }
        }
        memcpy(words, filtered_words, sizeof(filtered_words));
        words_size = count;
        attempts++;
    }
    printf("Either you took too many guesses, or you did not find the secret word.
");
}

int main() {
    char secret[7] = "hamada";
    char words[2][7] = {"hamada", "khaled"};
    int allowedGuesses = 10;
    Master master = { .secret = "hamada", .guess_count = 0 };
    findSecretWord(words, 2, &master, allowedGuesses);
    return 0;
}