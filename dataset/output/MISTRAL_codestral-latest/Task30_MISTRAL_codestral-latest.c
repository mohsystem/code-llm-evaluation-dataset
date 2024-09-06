#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longest(char *s1, char *s2) {
    int count[26] = {0};
    char *result = (char*)malloc(sizeof(char) * 27);
    int i, j = 0;

    for(i = 0; i < strlen(s1); i++) {
        count[s1[i] - 'a'] = 1;
    }

    for(i = 0; i < strlen(s2); i++) {
        count[s2[i] - 'a'] = 1;
    }

    for(i = 0; i < 26; i++) {
        if(count[i] == 1) {
            result[j++] = 'a' + i;
        }
    }

    result[j] = '\0';
    return result;
}

int main() {
    printf("%s", longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
    return 0;
}