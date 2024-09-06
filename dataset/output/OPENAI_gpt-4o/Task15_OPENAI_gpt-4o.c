#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** buildTower(int nFloors) {
    char** tower = (char**)malloc(nFloors * sizeof(char*));
    for (int i = 1; i <= nFloors; i++) {
        int paddingSize = nFloors - i;
        int starSize = 2 * i - 1;
        tower[i - 1] = (char*)malloc((nFloors * 2) * sizeof(char));
        memset(tower[i - 1], ' ', nFloors * 2 - 1);
        memset(tower[i - 1] + paddingSize, '*', starSize);
        tower[i - 1][nFloors * 2 - 1] = '\0';
    }
    return tower;
}

int main() {
    int nFloors = 6;
    char** tower = buildTower(nFloors);
    for (int i = 0; i < nFloors; i++) {
        printf("%s\n", tower[i]);
        free(tower[i]);
    }
    free(tower);
    return 0;
}