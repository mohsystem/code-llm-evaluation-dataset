#include <stdio.h>
#include <ctype.h>

int isIsogram(char str[]) {
    int count[26] = {0};
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (count[c - 'a'] == 1) {
            return 0;
        }
        count[c - 'a'] = 1;
    }
    return 1;
}

int main() {
    printf("%d
", isIsogram("Dermatoglyphics")); // 1
    printf("%d
", isIsogram("aba")); // 0
    printf("%d
", isIsogram("moOse")); // 0
    return 0;
}