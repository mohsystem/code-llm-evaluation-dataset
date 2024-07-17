// C
#include <stdbool.h>

bool isValidWalk(const char *walk) {
    int len = 0;
    while (walk[len] != '\0') len++;
    if (len != 10) return false;
    int x = 0, y = 0;
    for (int i = 0; i < len; i++) {
        switch (walk[i]) {
            case 'n': y++; break;
            case 's': y--; break;
            case 'e': x++; break;
            case 'w': x--; break;
        }
    }
    return x == 0 && y == 0;
}