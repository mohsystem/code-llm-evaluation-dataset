
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** towerBuilder(int nFloors) {
    char** tower = (char**)malloc(nFloors * sizeof(char*));
    int width = 2 * nFloors - 1;
    
    for (int i = 0; i < nFloors; i++) {
        tower[i] = (char*)malloc((width + 1) * sizeof(char));
        memset(tower[i], \' \', width);
        for (int j = nFloors - i - 1; j < nFloors + i; j++) {
            tower[i][j] = \'*\';
        }
        tower[i][width] = \'\\0\';
    }
    
    return tower;
}

int main() {
    int nFloors = 6;
    char** tower = towerBuilder(nFloors);
    
    for (int i = 0; i < nFloors; i++) {
        printf("%s\
", tower[i]);
        free(tower[i]);
    }
    free(tower);
    
    return 0;
}
