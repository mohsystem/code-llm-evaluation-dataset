#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isPangram(const char* s) {
    bool alphabet[26] = { false };
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            alphabet[tolower(s[i]) - 'a'] = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[] = "The quick brown fox jumps over the lazy dog";
    printf("%s\n", isPangram(s) ? "true" : "false");  // Output: true
    return 0;
}