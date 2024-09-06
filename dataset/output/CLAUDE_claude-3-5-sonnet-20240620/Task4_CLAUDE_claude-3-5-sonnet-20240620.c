
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char *str) {
    int seen[26] = {0};
    for (int i = 0; str[i] != '\\0'; i++) {
        int index = tolower(str[i]) - 'a';
        if (seen[index]) return false;
        seen[index] = 1;
    }
    return true;
}

int main() {
    printf("%s\\n", is_isogram("Dermatoglyphics") ? "true" : "false");  // true
    printf("%s\\n", is_isogram("aba") ? "true" : "false");  // false
    printf("%s\\n", is_isogram("moOse") ? "true" : "false");  // false
    return 0;
}
