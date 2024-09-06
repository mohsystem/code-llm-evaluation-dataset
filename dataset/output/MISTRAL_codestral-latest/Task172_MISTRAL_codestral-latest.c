#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            char* sub = (char*)malloc(i + 1);
            strncpy(sub, s, i);
            sub[i] = '\0';
            char* concat = (char*)malloc(n + 1);
            strcpy(concat, "");
            for (int j = 0; j < n / i; j++) {
                strcat(concat, sub);
            }
            if (strcmp(concat, s) == 0) {
                free(sub);
                free(concat);
                return true;
            }
            free(sub);
            free(concat);
        }
    }
    return false;
}

int numDistinct(char* text) {
    int n = strlen(text);
    int count = 0;
    for (int i = 1; i <= n / 2; i++) {
        char* sub = (char*)malloc(i + 1);
        strncpy(sub, text, i);
        sub[i] = '\0';
        if (repeatedSubstringPattern(sub)) {
            count++;
        }
        free(sub);
    }
    return count;
}

int main() {
    char text[] = "abcabcabc";
    printf("%d\n", numDistinct(text));
    return 0;
}