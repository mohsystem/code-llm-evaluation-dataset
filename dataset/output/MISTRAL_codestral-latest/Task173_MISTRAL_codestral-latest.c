#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 30000
#define MOD (1LL << 32)
#define ALPHABET_SIZE 26

typedef unsigned long long ull;

ull hash_values[MAX_SIZE];
ull powers[MAX_SIZE];

char* longestDupSubstring(char* s) {
    int n = strlen(s);
    int nums[n];
    for (int i = 0; i < n; i++) {
        nums[i] = s[i] - 'a';
    }

    int check(int length) {
        ull h = 0;
        for (int i = 0; i < length; i++) {
            h = (h * ALPHABET_SIZE + nums[i]) % MOD;
        }
        hash_values[0] = h;
        powers[0] = 1;
        for (int i = 1; i <= length; i++) {
            powers[i] = (powers[i - 1] * ALPHABET_SIZE) % MOD;
        }
        for (int start = 1; start <= n - length; start++) {
            h = (h * ALPHABET_SIZE - nums[start - 1] * powers[length - 1] + nums[start + length - 1]) % MOD;
            hash_values[start] = h;
            for (int j = start - 1; j >= 0; j--) {
                if (hash_values[start] == hash_values[j]) {
                    return j;
                }
            }
        }
        return -1;
    }

    int start = -1, length = 0;
    for (int k = 1; k < n; k++) {
        int pos = check(k);
        if (pos != -1 && k > length) {
            start = pos;
            length = k;
        }
    }
    if (start != -1) {
        char* result = (char*)malloc((length + 1) * sizeof(char));
        strncpy(result, s + start, length);
        result[length] = '\0';
        return result;
    }
    return "";
}