#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool XO(const char* str) {
    int xCount = 0, oCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) == 'x')
            xCount++;
        else if (tolower(str[i]) == 'o')
            oCount++;
    }
    return xCount == oCount;
}

int main() {
    printf("%d\n", XO("ooxx"));  // 1 (True)
    printf("%d\n", XO("xooxx"));  // 0 (False)
    printf("%d\n", XO("ooxXm"));  // 1 (True)
    printf("%d\n", XO("zpzpzpp"));  // 1 (True)
    printf("%d\n", XO("zzoo"));  // 0 (False)
    
    return 0;
}