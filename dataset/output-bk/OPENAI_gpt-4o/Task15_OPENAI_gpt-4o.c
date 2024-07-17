#include <stdio.h>
#include <string.h>

void buildTower(int nFloors) {
    for (int i = 0; i < nFloors; i++) {
        char floor[nFloors * 2];
        memset(floor, ' ', nFloors * 2 - 1);
        floor[nFloors * 2 - 1] = '\0';
        memset(floor + nFloors - i - 1, '*', 2 * i + 1);
        printf("%s
", floor);
    }
}

int main() {
    buildTower(3);
    buildTower(6);
    return 0;
}