
#include <string.h>
#include <stdlib.h>

char* shortestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) {
        return "";
    }
    
    int len = strlen(s);
    char* rev = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - 1 - i];
    }
    rev[len] = \'\\0\';
    
    char* temp = (char*)malloc((2 * len + 2) * sizeof(char));
    strcpy(temp, s);
    temp[len] = \'#\';
    strcat(temp, rev);
    
    int* lps = (int*)calloc(2 * len + 1, sizeof(int));
    
    int length = 0;
    int i = 1;
    while (i < 2 * len + 1) {
        if (temp[i] == temp[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    char* result = (char*)malloc((2 * len + 1) * sizeof(char));
    strncpy(result, rev, len - lps[2 * len]);
    strcat(result, s);
    
    free(rev);
    free(temp);
    free(lps);
    
    return result;
}
