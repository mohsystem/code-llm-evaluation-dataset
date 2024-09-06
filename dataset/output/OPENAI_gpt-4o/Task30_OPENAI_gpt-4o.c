#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void longest(const char *s1, const char *s2, char *result) {
    int count[26] = {0};
    while (*s1) count[*s1++ - 'a'] = 1;
    while (*s2) count[*s2++ - 'a'] = 1;
    char *p = result;
    for (char c = 'a'; c <= 'z'; c++) {
        if (count[c - 'a']) *p++ = c;
    }
    *p = '\0';
}

int main() {
    char a[] = "xyaabbbccccdefww";
    char b[] = "xxxxyyyyabklmopq";
    char result[27];

    longest(a, b, result);
    printf("%s\n", result);

    char c[] = "abcdefghijklmnopqrstuvwxyz";
    longest(c, c, result);
    printf("%s\n", result);

    return 0;
}