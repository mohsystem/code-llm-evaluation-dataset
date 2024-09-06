
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* accum(const char* s) {
    int len = strlen(s);
    char* result = malloc(len * (len + 1) / 2 + len);
    int index = 0;

    for (int i = 0; i < len; i++) {
        result[index++] = toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result[index++] = tolower(s[i]);
        }
        if (i < len - 1) {
            result[index++] = '-';
        }
    }
    result[index] = '\\0';
    return result;
}

int main() {
    char* result;

    result = accum("abcd");
    printf("%s\\n", result);
    free(result);

    result = accum("RqaEzty");
    printf("%s\\n", result);
    free(result);

    result = accum("cwAt");
    printf("%s\\n", result);
    free(result);

    return 0;
}
