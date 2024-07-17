#include <stdio.h>
#include <string.h>

void longest(char* s1, char* s2, char* result) {
    int i, j, k = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char combined[len1 + len2 + 1];
    strcpy(combined, s1);
    strcat(combined, s2);
    int unique[26] = {0};
    for (i = 0; i < len1 + len2; i++) {
        unique[combined[i] - 'a'] = 1;
    }
    for (i = 0; i < 26; i++) {
        if (unique[i]) {
            result[k++] = 'a' + i;
        }
    }
    result[k] = '\0';
}

int main() {
    char result[27];
    longest("xyaabbbccccdefww", "xxxxyyyyabklmopq", result);
    printf("%s
", result);
    longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", result);
    printf("%s
", result);
    return 0;
}