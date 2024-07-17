#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool XO(const char *str) {
    int xCount = 0;
    int oCount = 0;

    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'x') {
            xCount++;
        } else if (c == 'o') {
            oCount++;
        }
    }

    return xCount == oCount;
}

int main() {
    printf("%s
", XO("ooxx") ? "true" : "false"); // true
    printf("%s
", XO("xooxx") ? "true" : "false"); // false
    printf("%s
", XO("ooxXm") ? "true" : "false"); // true
    printf("%s
", XO("zpzpzpp") ? "true" : "false"); // true
    printf("%s
", XO("zzoo") ? "true" : "false"); // false
    return 0;
}