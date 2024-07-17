#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *accum(char *s) {
    int len = strlen(s);
    char *result = (char *) malloc(sizeof(char) * (len * (len + 1) / 2 + len));
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (i > 0) {
            result[index++] = '-';
        }
        result[index++] = toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result[index++] = tolower(s[i]);
        }
    }
    result[index] = '\0';
    return result;
}

int main() {
    printf("%s
", accum("abcd"));
    printf("%s
", accum("RqaEzty"));
    printf("%s
", accum("cwAt"));
    return 0;
}