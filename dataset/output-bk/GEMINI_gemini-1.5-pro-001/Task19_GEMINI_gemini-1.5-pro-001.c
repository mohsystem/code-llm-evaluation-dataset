#include <stdio.h>
#include <string.h>

void spinWords(char *sentence, char *result) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        if (strlen(word) >= 5) {
            for (int i = strlen(word) - 1; i >= 0; i--) {
                strncat(result, &word[i], 1);
            }
        } else {
            strcat(result, word);
        }
        word = strtok(NULL, " ");
        if (word != NULL) {
            strcat(result, " ");
        }
    }
}

int main() {
    char sentence1[] = "Hey fellow warriors";
    char sentence2[] = "This is a test";
    char sentence3[] = "This is another test";
    char result[100];

    memset(result, 0, sizeof(result));
    spinWords(sentence1, result);
    printf("%s
", result);

    memset(result, 0, sizeof(result));
    spinWords(sentence2, result);
    printf("%s
", result);

    memset(result, 0, sizeof(result));
    spinWords(sentence3, result);
    printf("%s
", result);

    return 0;
}