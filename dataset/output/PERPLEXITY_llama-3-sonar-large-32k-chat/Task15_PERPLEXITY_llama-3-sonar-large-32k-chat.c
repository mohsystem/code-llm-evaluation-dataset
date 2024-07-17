#include <stdio.h>
#include <string.h>

int main() {
    int floors = 6;
    char tower[floors][floors*2 + 1];
    for (int i = 0; i < floors; i++) {
        for (int j = 0; j < floors - i - 1; j++) {
            tower[i][j] = ' ';
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            tower[i][floors - i - 1 + j] = '*';
        }
        for (int j = 0; j < floors - i - 1; j++) {
            tower[i][floors + i + j + 1] = ' ';
        }
        tower[i][floors + i + 1] = '\0';
    }
    for (int i = 0; i < floors; i++) {
        printf("%s
", tower[i]);
    }
    return 0;
}