#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** towerBuilder(int nFloors, int* returnSize) {
    char** tower = malloc(nFloors * sizeof(char*));
    *returnSize = nFloors;
    for (int i = 0; i < nFloors; i++) {
        tower[i] = malloc((2 * nFloors) * sizeof(char));
        memset(tower[i], ' ', 2 * nFloors - 1);
        tower[i][nFloors - i - 1] = '\0';
        for (int j = nFloors - i - 1; j < nFloors + i; j++) {
            tower[i][j] = '*';
        }
    }
    return tower;
}