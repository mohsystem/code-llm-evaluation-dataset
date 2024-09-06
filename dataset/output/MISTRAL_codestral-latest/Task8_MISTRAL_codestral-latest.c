#include <stdio.h>

char findMissingLetter(char array[], int size) {
    for (int i = 1; i < size; i++) {
        if (array[i] - array[i - 1] > 1) {
            return (char) (array[i] - 1);
        }
    }
    return '\0';
}