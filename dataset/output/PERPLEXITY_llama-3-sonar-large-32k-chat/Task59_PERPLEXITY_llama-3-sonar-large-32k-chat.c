#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* accum(const char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len * len / 2 + len) * sizeof(char));
    int index = 0;
    for (int i = 0; i < len; i++) {
        result[index++] = toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result[index++] = tolower(s[i]);
        }
        if (i < len - 1) result[index++] = '-';
    }
    result[index] = '\0';
    return result;
}

int main() {
    printf("%s\n", accum("abcd"));
    printf("%s\n", accum("RqaEzty"));
    printf("%s\n", accum("cwAt"));
    return 0;
}