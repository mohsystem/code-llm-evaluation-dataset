#include <stdio.h>
#include <string.h>
#include <ctype.h>

void accum(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (i > 0) printf("-");
        printf("%c", toupper(s[i]));
        for (int j = 0; j < i; j++) {
            printf("%c", tolower(s[i]));
        }
    }
}