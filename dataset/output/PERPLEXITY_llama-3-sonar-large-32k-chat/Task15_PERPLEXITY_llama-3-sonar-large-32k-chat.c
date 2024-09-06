#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **towerBuilder(int nFloors) {
    char **tower = (char **)malloc(nFloors * sizeof(char *));
    for (int i = 0; i < nFloors; i++) {
        tower[i] = (char *)malloc((4 * nFloors - 2 * i) * sizeof(char));
        for (int j = 0; j < nFloors - i - 1; j++) {
            tower[i][j] = ' ';
        }
        for (int j = nFloors - i - 1; j < 2 * nFloors - i - 1; j++) {
            tower[i][j] = '*';
        }
        for (int j = 2 * nFloors - i - 1; j < 4 * nFloors - 2 * i; j++) {
            tower[i][j] = ' ';
        }
        tower[i][4 * nFloors - 2 * i] = '\0';
    }
    return tower;
}