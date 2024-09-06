#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toJadenCase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (i == 0 || str[i - 2] == ' ') {
            str[i] = toupper(str[i]);
        }
    }
}