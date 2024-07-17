#include <stdio.h>

char findMissingLetter(char chars[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (chars[i + 1] - chars[i] > 1) {
            return chars[i] + 1;
        }
    }
    return '\0';
}

int main() {
    char chars1[] = {'a','b','c','d','f'};
    char chars2[] = {'O','Q','R','S'};
    printf("%c
", findMissingLetter(chars1, 5));  // 'e'
    printf("%c
", findMissingLetter(chars2, 4));  // 'P'
    return 0;
}