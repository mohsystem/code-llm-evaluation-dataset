#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char* spinWords(const char* sentence) {
    char* result = malloc(strlen(sentence) + 1);
    strcpy(result, sentence);
    char* token = strtok(result, " ");
    int index = 0;
    while (token != NULL) {
        if (strlen(token) >= 5) {
            reverse(token, strlen(token));
        }
        if (index > 0) {
            strcat(result, " ");
        }
        strcat(result, token);
        token = strtok(NULL, " ");
        index++;
    }
    return result;
}