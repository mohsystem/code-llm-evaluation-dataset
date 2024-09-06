#include <string.h>
#include <stdlib.h>

char* shortestPalindrome(char* s) {
    int i = 0;
    for (int j = strlen(s) - 1; j >= 0; j--) {
        if (s[i] == s[j]) {
            i++;
        }
    }
    if (i == strlen(s)) {
        return s;
    }
    char* suffix = strdup(s + i);
    char* prefix = strdup(suffix);
    for (int j = 0; j < strlen(prefix) / 2; j++) {
        char temp = prefix[j];
        prefix[j] = prefix[strlen(prefix) - j - 1];
        prefix[strlen(prefix) - j - 1] = temp;
    }
    char* result = malloc(strlen(prefix) + strlen(shortestPalindrome(strndup(s, i))) + strlen(suffix) + 1);
    strcpy(result, prefix);
    strcat(result, shortestPalindrome(strndup(s, i)));
    strcat(result, suffix);
    free(prefix);
    free(suffix);
    return result;
}