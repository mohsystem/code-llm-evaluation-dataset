#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isIsogram(const char *str) {
    bool charSet[26] = {false};
    for (int i = 0; str[i]; i++) {
        int index = tolower(str[i]) - 'a';
        if (charSet[index]) {
            return false;
        }
        charSet[index] = true;
    }
    return true;
}

int main() {
    printf("%d
", isIsogram("Dermatoglyphics")); // 1 (true)
    printf("%d
", isIsogram("aba")); // 0 (false)
    printf("%d
", isIsogram("moOse")); // 0 (false)
    return 0;
}