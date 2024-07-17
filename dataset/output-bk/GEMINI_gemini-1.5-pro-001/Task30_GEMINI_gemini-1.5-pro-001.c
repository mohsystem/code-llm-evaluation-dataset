#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longest(char *s1, char *s2) {
    int seen[26] = {0};
    char *result = malloc(27 * sizeof(char));
    int len = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        int index = s1[i] - 'a';
        if (!seen[index]) {
            result[len++] = s1[i];
            seen[index] = 1;
        }
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        int index = s2[i] - 'a';
        if (!seen[index]) {
            result[len++] = s2[i];
            seen[index] = 1;
        }
    }
    result[len] = '\0';
    // Bubble sort for simplicity
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                char temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    return result;
}

int main() {
    printf("%s
", longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
    printf("%s
", longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    return 0;
}