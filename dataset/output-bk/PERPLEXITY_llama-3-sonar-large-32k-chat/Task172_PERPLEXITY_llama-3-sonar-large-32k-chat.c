#include <string.h>
#include <stdio.h>

int isPalindrome(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int distinctEchoSubstrings(char *text) {
    int n = strlen(text);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            char s[j - i + 1];
            strncpy(s, text + i, j - i);
            s[j - i] = '\0';
            if (isPalindrome(s) && (j - i) % 2 == 0) {
                res++;
            }
        }
    }
    return res;
}