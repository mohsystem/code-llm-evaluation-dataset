#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char *longest(const char *s1, const char *s2) {
    int char_seen[26] = {0};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = malloc((len1 + len2 + 1) * sizeof(char));
    int count = 0;
    for (int i = 0; i < len1; i++) {
        if (char_seen[s1[i] - 'a'] == 0) {
            result[count++] = s1[i];
            char_seen[s1[i] - 'a'] = 1;
        }
    }
    for (int i = 0; i < len2; i++) {
        if (char_seen[s2[i] - 'a'] == 0) {
            result[count++] = s2[i];
            char_seen[s2[i] - 'a'] = 1;
        }
    }
    result[count] = '\0';
    qsort(result, count, sizeof(char), cmpfunc);
    return result;
}