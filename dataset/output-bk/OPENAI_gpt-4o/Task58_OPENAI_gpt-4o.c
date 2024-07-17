#include <stdio.h>
#include <ctype.h>

int XO(const char* str) {
    int countX = 0, countO = 0;
    while (*str) {
        if (tolower(*str) == 'x') countX++;
        if (tolower(*str) == 'o') countO++;
        str++;
    }
    return countX == countO;
}

int main() {
    printf("%d
", XO("ooxx"));
    printf("%d
", XO("xooxx"));
    printf("%d
", XO("ooxXm"));
    printf("%d
", XO("zpzpzpp"));
    printf("%d
", XO("zzoo"));
    return 0;
}