#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check(char *sentence) {
    bool alphabet[26] = {false};
    for (int i = 0; sentence[i] != '\0'; i++) {
        char c = tolower((unsigned char)sentence[i]);
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a'] = true;
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
    printf("%d
", check("The quick brown fox jumps over the lazy dog")); // 1
    printf("%d
", check("Hello World")); // 0
    return 0;
}