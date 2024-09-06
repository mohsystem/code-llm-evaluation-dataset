#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void spinWords(const char *sentence) {
    char result[1000] = "";
    char word[100] = "";
    int wordIndex = 0;
    int resultIndex = 0;

    for (int i = 0; i <= strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            if (wordIndex >= 5) {
                reverse(word, wordIndex);
            }
            for (int j = 0; j < wordIndex; j++) {
                result[resultIndex++] = word[j];
            }
            if (sentence[i] == ' ') {
                result[resultIndex++] = ' ';
            }
            wordIndex = 0;
        } else {
            word[wordIndex++] = sentence[i];
        }
    }

    printf("%s", result);
}