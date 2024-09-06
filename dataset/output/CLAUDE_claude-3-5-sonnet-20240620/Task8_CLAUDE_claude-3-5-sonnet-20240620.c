
#include <stdio.h>

char findMissingLetter(char* chars, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (chars[i + 1] - chars[i] > 1) {
            return chars[i] + 1;
        }
    }
    return ' ';
}

int main() {
    char arr1[] = {'a','b','c','d','f'};
    char arr2[] = {'O','Q','R','S'};
    
    printf("%c\\n", findMissingLetter(arr1, sizeof(arr1)/sizeof(arr1[0])));  // Output: e
    printf("%c\\n", findMissingLetter(arr2, sizeof(arr2)/sizeof(arr2[0])));  // Output: P
    
    return 0;
}
