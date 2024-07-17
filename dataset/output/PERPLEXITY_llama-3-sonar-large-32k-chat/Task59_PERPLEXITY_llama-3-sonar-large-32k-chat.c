#include <stdio.h>
#include <string.h>
#include <ctype.h>

void accum(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", toupper(s[i]));
        for (int j = 0; j < i; j++) {
            printf("%c", tolower(s[j]));
        }
        if (i < strlen(s) - 1) {
            printf("-");
        }
    }
    printf("
");
}

int main() {
    char s1[] = "abcd";
    char s2[] = "RqaEzty";
    char s3[] = "cwAt";
    accum(s1);
    accum(s2);
    accum(s3);
    return 0;
}