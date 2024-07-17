#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longest(char *s1, char *s2) {
    int count[26] = {0};
    int i;
    for (i = 0; i < strlen(s1); i++) {
        count[s1[i] - 'a'] = 1;
    }
    for (i = 0; i < strlen(s2); i++) {
        count[s2[i] - 'a'] = 1;
    }
    for (i = 0; i < 26; i++) {
        if (count[i] == 1) {
            printf("%c", i + 'a');
        }
    }
    printf("
");
}

int main() {
    longest("xyaabbbccccdefww", "xxxxyyyyabklmopq");
    longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
    return 0;
}