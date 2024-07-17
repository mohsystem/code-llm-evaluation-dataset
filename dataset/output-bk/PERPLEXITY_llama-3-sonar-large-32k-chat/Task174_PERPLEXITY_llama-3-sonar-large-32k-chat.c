#include <string.h>

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    char* rev_s = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        rev_s[i] = s[len - i - 1];
    }
    rev_s[len] = '\0';
    for (int i = 0; i < len; i++) {
        if (strstr(s, rev_s + i) == s) {
            char* res = (char*)malloc((len * 2 + 1) * sizeof(char));
            strcpy(res, rev_s);
            strcat(res, s);
            return res;
        }
    }
    return "";
}