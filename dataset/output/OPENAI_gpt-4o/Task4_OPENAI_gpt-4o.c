#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isIsogram(const char *s) {
    int len = strlen(s);
    bool seen[26] = {false};
    for (int i = 0; i < len; i++) {
        char c = tolower(s[i]);
        if (seen[c - 'a']) return false;
        seen[c - 'a'] = true;
    }
    return true;
}

int main() {
    printf("%d\n", isIsogram("Dermatoglyphics"));  // True
    printf("%d\n", isIsogram("aba"));              // False
    printf("%d\n", isIsogram("moOse"));            // False
    return 0;
}