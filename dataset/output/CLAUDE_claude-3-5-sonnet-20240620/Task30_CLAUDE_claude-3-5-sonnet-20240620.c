
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longest(const char* s1, const char* s2) {
    int chars[26] = {0};
    int i, len1 = strlen(s1), len2 = strlen(s2);
    
    for (i = 0; i < len1; i++) chars[s1[i] - \'a\'] = 1;
    for (i = 0; i < len2; i++) chars[s2[i] - \'a\'] = 1;
    
    char* result = (char*)malloc(27 * sizeof(char));
    int index = 0;
    
    for (i = 0; i < 26; i++) {
        if (chars[i]) result[index++] = \'a\' + i;
    }
    result[index] = \'\\0\';
    
    return result;
}

int main() {
    printf("%s\
", longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
    printf("%s\
", longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
    return 0;
}
