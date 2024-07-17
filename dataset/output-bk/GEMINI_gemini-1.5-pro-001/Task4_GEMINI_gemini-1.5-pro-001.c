#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char *str) {
    if (strlen(str) == 0) {
        return true;
    }

    int letters[26] = {0}; 

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            int index = c - 'a'; 
            if (letters[index] > 0) {
                return false; 
            } else {
                letters[index]++;
            }
        }
    }
    return true; 
}
int main() {
    printf("%s
", is_isogram("Dermatoglyphics") ? "true" : "false");
    printf("%s
", is_isogram("aba") ? "true" : "false");
    printf("%s
", is_isogram("moOse") ? "true" : "false");
    return 0;
}