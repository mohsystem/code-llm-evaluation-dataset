#include <stdio.h>

char findMissingLetter(char array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] - array[i] != 1) {
            return array[i] + 1;
        }
    }
    return '\0';
}

int main() {
    char arr1[] = { 'a', 'b', 'c', 'd', 'f' };
    char arr2[] = { 'O', 'Q', 'R', 'S' };
    printf("%c\n", findMissingLetter(arr1, 5)); // e
    printf("%c\n", findMissingLetter(arr2, 4)); // P
    return 0;
}