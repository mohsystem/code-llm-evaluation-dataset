#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
}

char* shortestPalindrome(char* s) {
    static char rev_s[50000];  // static to avoid returning local variable address
    strcpy(rev_s, s);
    reverse(rev_s);
    for (int i = 0; i <= strlen(s); i++) {
        if (strncmp(s, rev_s + i, strlen(s) - i) == 0) {
            char *result = (char*)malloc(50000);
            strcpy(result, rev_s);
            result[i] = '\0';
            strcat(result, s);
            return result;
        }
    }
    return "";
}

int main() {
    char s[] = "aacecaaa";
    printf("%s", shortestPalindrome(s));
    return 0;
}