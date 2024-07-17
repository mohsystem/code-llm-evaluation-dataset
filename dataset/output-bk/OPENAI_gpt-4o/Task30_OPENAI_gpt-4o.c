#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void longest(char *s1, char *s2, char *result) {
    bool seen[26] = { false };
    int pos = 0;
    
    for (int i = 0; i < strlen(s1); i++) seen[s1[i] - 'a'] = true;
    for (int i = 0; i < strlen(s2); i++) seen[s2[i] - 'a'] = true;
    
    for (int i = 0; i < 26; i++) {
        if (seen[i]) result[pos++] = 'a' + i;
    }
    result[pos] = '\0';
}

int main() {
    char result[27];
    longest("xyaabbbccccdefww", "xxxxyyyyabklmopq", result);
    printf("%s
", result); // "abcdefklmopqwxy"
    
    longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", result);
    printf("%s
", result); // "abcdefghijklmnopqrstuvwxyz"
    
    return 0;
}