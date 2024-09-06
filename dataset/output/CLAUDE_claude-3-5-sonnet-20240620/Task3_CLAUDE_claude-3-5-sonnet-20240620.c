
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPangram(const char* str) {
    bool alphabet[26] = {false};
    int i;
    
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            alphabet[tolower(str[i]) - 'a'] = true;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    const char* test = "The quick brown fox jumps over the lazy dog";
    printf("%s\\n", isPangram(test) ? "true" : "false");
    return 0;
}
