
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPangram(const char* sentence) {
    bool letters[26] = {false};
    int count = 0;

    for (int i = 0; sentence[i] != \'\\0\'; i++) {
        char c = tolower(sentence[i]);
        if (isalpha(c)) {
            int index = c - \'a\';
            if (!letters[index]) {
                letters[index] = true;
                count++;
            }
        }
    }

    return count == 26;
}

int main() {
    const char* test1 = "The quick brown fox jumps over the lazy dog";
    const char* test2 = "This is not a pangram";
    printf("%s\
", isPangram(test1) ? "true" : "false");  // true
    printf("%s\
", isPangram(test2) ? "true" : "false");  // false
    return 0;
}
