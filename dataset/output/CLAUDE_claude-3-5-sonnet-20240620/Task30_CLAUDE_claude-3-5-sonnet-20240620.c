
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longest(const char* s1, const char* s2) {
    int counts[26] = {0};
    int i, len = 0;
    char* result;

    while (*s1) counts[*s1++ - 'a'] = 1;
    while (*s2) counts[*s2++ - 'a'] = 1;

    for (i = 0; i < 26; i++) {
        if (counts[i]) len++;
    }

    result = (char*)malloc(len + 1);
    result[len] = '\\0';

    for (i = 0; i < 26; i++) {
        if (counts[i]) {
            *result++ = i + 'a';
        }
    }

    return result - len;
}

int main() {
    printf("%s\\n", longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
    printf("%s\\n", longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    return 0;
}
