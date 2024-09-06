#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *accum(const char *s) {
    int len = strlen(s);
    char *result = malloc(len * 4 + 1); // worst case: "A-Bb-Ccc-...-Zzz...zzz"
    int pos = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            result[pos++] = '-';
        }
        result[pos++] = toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result[pos++] = tolower(s[i]);
        }
    }
    result[pos] = '\0';
    return result;
}