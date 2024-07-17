#include <stdio.h>
#include <ctype.h>
#include <string.h>

void accum(const char* s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (i > 0) printf("-");
        putchar(toupper(s[i]));
        for (int j = 0; j < i; j++) {
            putchar(tolower(s[i]));
        }
    }
    printf("
");
}

int main() {
    accum("abcd");       // Output: A-Bb-Ccc-Dddd
    accum("RqaEzty");    // Output: R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy
    accum("cwAt");       // Output: C-Ww-Aaa-Tttt
    return 0;
}