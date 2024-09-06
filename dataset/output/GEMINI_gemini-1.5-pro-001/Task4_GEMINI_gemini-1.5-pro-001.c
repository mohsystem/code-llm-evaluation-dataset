#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isIsogram(char *str) {
    if (strlen(str) == 0) {
        return 1; 
    }
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i + 1; str[j] != '\0'; j++) {
            if (str[i] == str[j]) {
                return 0; 
            }
        }
    }
    return 1; 
}