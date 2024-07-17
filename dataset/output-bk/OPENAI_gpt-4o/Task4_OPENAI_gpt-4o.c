#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isIsogram(const char *str) {
    int length = strlen(str);
    bool letters[26] = { false };

    for (int i = 0; i < length; i++) {
        char c = tolower(str[i]);
        if (letters[c - 'a']) {
            return false;
        }
        letters[c - 'a'] = true;
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