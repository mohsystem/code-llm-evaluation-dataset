
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidWalk(const char *walk) {
    if (strlen(walk) != 10) {
        return false;
    }
    
    int x = 0, y = 0;
    for (int i = 0; walk[i] != '\\0'; i++) {
        switch (walk[i]) {
            case 'n': y++; break;
            case 's': y--; break;
            case 'e': x++; break;
            case 'w': x--; break;
        }
    }
    
    return x == 0 && y == 0;
}

int main() {
    printf("%s\\n", isValidWalk("nsnsnsnsns") ? "true" : "false");  // true
    printf("%s\\n", isValidWalk("wewewewewewewe") ? "true" : "false");  // false
    printf("%s\\n", isValidWalk("w") ? "true" : "false");  // false
    printf("%s\\n", isValidWalk("nnnsnsnsns") ? "true" : "false");  // false
    return 0;
}
