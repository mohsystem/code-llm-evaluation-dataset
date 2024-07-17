#include <stdio.h>
#include <string.h>
#include <ctype.h>

int xo(char *str) {
    int xCount = 0;
    int oCount = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (tolower(str[i]) == 'x') xCount++;
        if (tolower(str[i]) == 'o') oCount++;
    }
    return xCount == oCount;
}

int main() {
    printf("%d
", xo("ooxx")); // 1
    printf("%d
", xo("xooxx")); // 0
    printf("%d
", xo("ooxXm")); // 1
    printf("%d
", xo("zpzpzpp")); // 1
    printf("%d
", xo("zzoo")); // 0
    return 0;
}