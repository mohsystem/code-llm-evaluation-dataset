#include <stdio.h>
#include <string.h>

int isValidWalk(char* walk[], int len) {
    int x = 0, y = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(walk[i], "n") == 0) y++;
        if (strcmp(walk[i], "s") == 0) y--;
        if (strcmp(walk[i], "e") == 0) x++;
        if (strcmp(walk[i], "w") == 0) x--;
    }
    return x == 0 && y == 0 && len == 10;
}

int main() {
    char* walk[] = {"n", "s", "e", "w", "n", "s", "e", "w", "n", "s"};
    int len = sizeof(walk) / sizeof(walk[0]);
    printf("%d
", isValidWalk(walk, len));
    return 0;
}