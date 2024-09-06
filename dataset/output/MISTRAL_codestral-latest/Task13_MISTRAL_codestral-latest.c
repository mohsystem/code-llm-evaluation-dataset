#include <stdbool.h>

bool isValidWalk(char walk[], int length) {
    if (length != 10) {
        return false;
    }
    int x = 0, y = 0;
    for (int i = 0; i < length; i++) {
        char direction = walk[i];
        if (direction == 'n') {
            y++;
        } else if (direction == 's') {
            y--;
        } else if (direction == 'e') {
            x++;
        } else if (direction == 'w') {
            x--;
        }
    }
    return x == 0 && y == 0;
}