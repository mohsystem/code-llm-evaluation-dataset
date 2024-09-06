#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* high(const char* inputString) {
    static char bestWord[100];
    char tempWord[100];
    int maxScore = 0, score = 0;

    const char* word = strtok((char*)inputString, " ");
    while (word != NULL) {
        score = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            score += tolower(word[i]) - 'a' + 1;
        }

        if (score > maxScore) {
            strcpy(bestWord, word);
            maxScore = score;
        }

        word = strtok(NULL, " ");
    }

    return bestWord;
}

int main() {
    char inputString[] = "abad test example";
    printf("%s\n", high(inputString));
    return 0;
}