#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPangram(const char* s) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++) {
        int found = 0;
        for (int j = 0; s[j]; j++) {
            if (tolower(s[j]) == alphabet[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("%d\n", isPangram("The quick brown fox jumps over the lazy dog"));  // 1
    printf("%d\n", isPangram("Hello World"));  // 0
    return 0;
}