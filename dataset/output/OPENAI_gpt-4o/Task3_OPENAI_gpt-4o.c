// C
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool isPangram(const char *sentence) {
    bool letters[26] = { false };
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            letters[tolower(sentence[i]) - 'a'] = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!letters[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    const char* sentence = "The quick brown fox jumps over the lazy dog";
    printf("%s
", isPangram(sentence) ? "True" : "False");
    return 0;
}