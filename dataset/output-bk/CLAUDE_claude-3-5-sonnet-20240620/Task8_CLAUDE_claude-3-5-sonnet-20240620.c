
#include <stdio.h>

char findMissingLetter(char* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] - array[i] > 1) {
            return array[i] + 1;
        }
    }
    return \' \';
}

int main() {
    char arr1[] = {\'a\', \'b\', \'c\', \'d\', \'f\'};
    char arr2[] = {\'O\', \'Q\', \'R\', \'S\'};
    
    printf("%c\
", findMissingLetter(arr1, sizeof(arr1)/sizeof(arr1[0])));
    printf("%c\
", findMissingLetter(arr2, sizeof(arr2)/sizeof(arr2[0])));
    
    return 0;
}
