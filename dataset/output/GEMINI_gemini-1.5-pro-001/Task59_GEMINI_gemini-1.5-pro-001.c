#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* accum(char* s) {
    int len = strlen(s);
    char* result = malloc(len * (len + 1) / 2 + len);
    if (result == NULL) {
        return NULL;
    }
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
    char* s1 = "abcd";
    char* result1 = accum(s1);
    printf("%s\n", result1);
    free(result1);

    char* s2 = "RqaEzty";
    char* result2 = accum(s2);
    printf("%s\n", result2);
    free(result2);

    char* s3 = "cwAt";
    char* result3 = accum(s3);
    printf("%s\n", result3);
    free(result3);

    return 0;
}