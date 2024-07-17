
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD ((1ULL << 63) - 1)

typedef unsigned long long ull;

char* rabinKarp(const char* s, int len, int sLen) {
    if (len == 0) return NULL;
    ull p = 1;
    for (int i = 0; i < len - 1; i++) {
        p = (p * 26) % MOD;
    }
    
    ull cur = 0;
    for (int i = 0; i < len; i++) {
        cur = (cur * 26 + s[i] - \'a\') % MOD;
    }
    
    ull* seen = (ull*)calloc(sLen, sizeof(ull));
    int seenSize = 0;
    seen[seenSize++] = cur;
    
    for (int i = len; i < sLen; i++) {
        cur = (cur * 26 - (s[i - len] - \'a\') * p % MOD + MOD) % MOD;
        cur = (cur + s[i] - \'a\') % MOD;
        for (int j = 0; j < seenSize; j++) {
            if (seen[j] == cur) {
                char* result = (char*)malloc((len + 1) * sizeof(char));
                strncpy(result, s + i - len + 1, len);
                result[len] = \'\\0\';
                free(seen);
                return result;
            }
        }
        seen[seenSize++] = cur;
    }
    free(seen);
    return NULL;
}

char* longestDupSubstring(char* s) {
    int left = 0, right = strlen(s);
    char* res = "";
    while (left < right) {
        int mid = left + (right - left) / 2;
        char* candidate = rabinKarp(s, mid, strlen(s));
        if (candidate != NULL) {
            left = mid + 1;
            free(res);
            res = candidate;
        } else {
            right = mid;
        }
    }
    return res;
}

int main() {
    char s[] = "banana";
    char* result = longestDupSubstring(s);
    printf("%s\
", result);
    free(result);
    return 0;
}
