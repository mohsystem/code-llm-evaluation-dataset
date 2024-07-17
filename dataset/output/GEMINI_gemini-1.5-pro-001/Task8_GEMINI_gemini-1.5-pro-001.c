#include <stdio.h>

char findMissingLetter(char array[], int array_size);

int main() {
    char arr1[] = {'a', 'b', 'c', 'd', 'f'};
    char arr2[] = {'O', 'Q', 'R', 'S'};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("%c
", findMissingLetter(arr1, size1));
    printf("%c
", findMissingLetter(arr2, size2));

    return 0;
}
char findMissingLetter(char array[], int array_size) {
    for (int i = 1; i < array_size; i++) {
        if (array[i] - array[i - 1] != 1) {
            return (char) (array[i] - 1);
        }
    }
    return ' ';
}