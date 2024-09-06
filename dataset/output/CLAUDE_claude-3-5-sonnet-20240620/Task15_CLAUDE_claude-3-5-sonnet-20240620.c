
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** towerBuilder(int nFloors) {
    char** tower = (char**)malloc(nFloors * sizeof(char*));
    for (int i = 0; i < nFloors; i++) {
        tower[i] = (char*)malloc((2 * nFloors + 1) * sizeof(char));
        int spaces = nFloors - i - 1;
        int stars = 2 * i + 1;
        
        memset(tower[i], ' ', spaces);
        memset(tower[i] + spaces, '*', stars);
        memset(tower[i] + spaces + stars, ' ', spaces);
        tower[i][2 * nFloors - 1] = '\\0';
    }
    return tower;
}

int main() {
    int nFloors = 3;
    char** tower = towerBuilder(nFloors);
    for (int i = 0; i < nFloors; i++) {
        printf("%s\\n", tower[i]);
        free(tower[i]);
    }
    free(tower);

    printf("\\n");

    nFloors = 6;
    tower = towerBuilder(nFloors);
    for (int i = 0; i < nFloors; i++) {
        printf("%s\\n", tower[i]);
        free(tower[i]);
    }
    free(tower);

    return 0;
}
