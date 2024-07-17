#include <stdio.h>
#include <stdbool.h>

bool isValid(char walk[], int length) {
    if (length != 10) return false;
    int x = 0, y = 0;
    for (int i = 0; i < length; i++) {
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
    char walk[10] = {'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'};
    printf("%s
", isValid(walk, 10) ? "true" : "false"); // should return true
    return 0;
}