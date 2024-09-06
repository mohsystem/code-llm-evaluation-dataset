#include <string.h>
#include <stdio.h>

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    char* a = (char*)malloc((len * 2 + 1) * sizeof(char));
    strcpy(a, s);
    strcat(a, "#");
    for (int i = len - 1; i >= 0; i--) {
        strcat(a, &s[i]);
    }
    int k[len * 2 + 1];
    k[0] = 0;
    for (int i = 1; i < len * 2 + 1; i++) {
        int j = k[i-1];
        while (j > 0 && a[i] != a[j]) {
            j = k[j-1];
        }
        k[i] = j + (a[i] == a[j]) ? 1 : 0;
    }
    char* res = (char*)malloc((len * 2 + 1) * sizeof(char));
    for (int i = len - k[len * 2]; i < len; i++) {
        res[len - k[len * 2] - i + len] = s[i];
    }
    strcpy(res + len - k[len * 2], s);
    return res;
}