#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) return s;
    char* rev_s = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        rev_s[i] = s[len - i - 1];
    }
    rev_s[len] = '\0';
    
    for (int i = 0; i <= len; i++) {
        if (strncmp(s, rev_s + i, len - i) == 0) {
            char* result = (char*)malloc(len + i + 1);
            strncpy(result, rev_s, i);
            strcpy(result + i, s);
            free(rev_s);
            return result;
        }
    }
    free(rev_s);
    return "";
}

int main() {
    char s1[] = "aacecaaa";
    char s2[] = "abcd";
    printf("%s
", shortestPalindrome(s1));  // Output: aaacecaaa
    printf("%s
", shortestPalindrome(s2));  // Output: dcbabcd
    return 0;
}