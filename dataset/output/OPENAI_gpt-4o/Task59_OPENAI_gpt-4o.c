#include <stdio.h>
#include <ctype.h>
#include <string.h>

void accum(const char *s, char *result) {
    for (int i = 0, pos = 0; s[i] != '\0'; i++) {
        if (i > 0) result[pos++] = '-';
        result[pos++] = toupper(s[i]);
        for (int j = 0; j < i; j++) {
            result[pos++] = tolower(s[i]);
        }
    }
}

int main() {
    char result[256];

    accum("abcd", result);
    printf("%s\n", result); // Output: A-Bb-Ccc-Dddd

    accum("RqaEzty", result);
    printf("%s\n", result); // Output: R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy

    accum("cwAt", result);
    printf("%s\n", result); // Output: C-Ww-Aaa-Tttt

    return 0;
}