#include <stdio.h>
#include <stdbool.h>

bool isValidWalk(char walk[], int length) {
    if (length != 10) return false;
    int x = 0, y = 0;
    for (int i = 0; i < length; i++) {
        switch (walk[i]) {
            case 'n': y += 1; break;
            case 's': y -= 1; break;
            case 'e': x += 1; break;
            case 'w': x -= 1; break;
        }
    }
    return x == 0 && y == 0;
}

int main() {
    char walk[] = {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'};
    int length = sizeof(walk) / sizeof(walk[0]);
    printf("%s\n", isValidWalk(walk, length) ? "true" : "false"); // Output: true
    return 0;
}