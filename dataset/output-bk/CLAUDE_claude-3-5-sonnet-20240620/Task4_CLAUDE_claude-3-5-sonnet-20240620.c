
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

bool isIsogram(const char *str) {
    bool letters[ALPHABET_SIZE] = {false};
    
    for (int i = 0; str[i] != \'\\0\'; i++) {
        int index = tolower(str[i]) - \'a\';
        if (letters[index]) {
            return false;
        }
        letters[index] = true;
    }
    return true;
}

int main() {
    printf("%s\
", isIsogram("Dermatoglyphics") ? "true" : "false");
    printf("%s\
", isIsogram("aba") ? "true" : "false");
    printf("%s\
", isIsogram("moOse") ? "true" : "false");
    return 0;
}
