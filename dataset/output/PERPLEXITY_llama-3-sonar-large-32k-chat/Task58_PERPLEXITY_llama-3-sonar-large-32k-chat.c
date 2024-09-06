#include <stdio.h>
#include <string.h>
#include <ctype.h>

int xo(char *s) {
    int xCount = 0, oCount = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (tolower(s[i]) == 'x') xCount++;
        if (tolower(s[i]) == 'o') oCount++;
    }
    return xCount == oCount;
}