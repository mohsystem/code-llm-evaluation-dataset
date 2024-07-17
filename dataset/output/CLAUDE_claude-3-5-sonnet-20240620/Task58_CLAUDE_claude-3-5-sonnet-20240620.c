
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool getXO(const char* str) {
    int x = 0, o = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == \'x\') x++;
        if (c == \'o\') o++;
    }
    return x == o;
}

int main() {
    printf("%d\
", getXO("ooxx"));
    printf("%d\
", getXO("xooxx"));
    printf("%d\
", getXO("ooxXm"));
    printf("%d\
", getXO("zpzpzpp"));
    printf("%d\
", getXO("zzoo"));
    return 0;
}
