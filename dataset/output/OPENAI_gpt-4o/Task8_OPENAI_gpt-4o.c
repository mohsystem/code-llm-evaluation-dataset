#include <stdio.h>

char findMissingLetter(char array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] != array[i] + 1) {
            return array[i] + 1;
        }
    }
    return '\0'; // This line should never be reached if input is valid
}

int main() {
    char array1[] = {'a', 'b', 'c', 'd', 'f'};
    char array2[] = {'O', 'Q', 'R', 'S'};
    
    printf("%c
", findMissingLetter(array1, sizeof(array1)/sizeof(array1[0]))); // Output: e
    printf("%c
", findMissingLetter(array2, sizeof(array2)/sizeof(array2[0]))); // Output: P
    
    return 0;
}