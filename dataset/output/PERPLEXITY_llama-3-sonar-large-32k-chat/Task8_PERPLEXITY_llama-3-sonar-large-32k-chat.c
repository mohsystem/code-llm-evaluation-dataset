#include <stdio.h>

char findMissingLetter(char array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i+1] - array[i] > 1) {
            return (char) (array[i] + 1);
        }
    }
    return ' ';
}

int main() {
    char array[] = {'a','b','c','d','f'};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%c\n", findMissingLetter(array, size));
    return 0;
}