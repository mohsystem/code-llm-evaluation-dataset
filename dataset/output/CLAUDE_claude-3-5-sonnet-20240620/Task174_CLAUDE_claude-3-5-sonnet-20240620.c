
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    char* rev = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - 1 - i];
    }
    rev[len] = '\\0';

    char* temp = (char*)malloc((2 * len + 2) * sizeof(char));
    sprintf(temp, "%s#%s", s, rev);

    int* lps = (int*)calloc(2 * len + 1, sizeof(int));
    
    for (int i = 1; i < 2 * len + 1; i++) {
        int j = lps[i-1];
        while (j > 0 && temp[i] != temp[j]) {
            j = lps[j-1];
        }
        if (temp[i] == temp[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    char* result = (char*)malloc((2 * len + 1) * sizeof(char));
    strncpy(result, rev, len - lps[2 * len]);
    strcat(result, s);

    free(rev);
    free(temp);
    free(lps);
    return result;
}

int main() {
    char* result1 = shortestPalindrome("aacecaaa");
    printf("%s\\n", result1);  // Output: "aaacecaaa"
    free(result1);

    char* result2 = shortestPalindrome("abcd");
    printf("%s\\n", result2);  // Output: "dcbabcd"
    free(result2);

    return 0;
}
