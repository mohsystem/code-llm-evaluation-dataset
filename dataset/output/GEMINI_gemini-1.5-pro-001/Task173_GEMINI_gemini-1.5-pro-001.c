#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 30000

char *rabinKarp(char *s, int length);
char *check(char *s, int left, int right);
char *longestDupSubstring(char *s);

char *longestDupSubstring(char *s) {
    int n = strlen(s);
    return check(s, 1, n);
}

char *check(char *s, int left, int right) {
    if (left > right) {
        return "";
    }
    int mid = left + (right - left) / 2;
    char *substring = rabinKarp(s, mid);
    if (strlen(substring) > 0) {
        return substring;
    } else {
        char *leftResult = check(s, left, mid - 1);
        char *rightResult = check(s, mid + 1, right);
        return strlen(leftResult) >= strlen(rightResult) ? leftResult : rightResult;
    }
}

char *rabinKarp(char *s, int length) {
    if (length == 0) {
        return "";
    }
    int n = strlen(s);
    long long modulus = (long long) pow(2, 32);
    long long a = 26;
    long long hash = 0;
    long long power = 1;
    for (int i = 0; i < length; i++) {
        hash = (hash * a + (s[i] - 'a')) % modulus;
        power = (power * a) % modulus;
    }
    long long *seen = (long long *) malloc(sizeof(long long) * (n - length + 1));
    seen[0] = hash;
    int seenCount = 1;
    for (int i = 1; i <= n - length; i++) {
        hash = (hash * a - (s[i - 1] - 'a') * power % modulus + modulus) % modulus;
        hash = (hash + (s[i + length - 1] - 'a')) % modulus;
        for (int j = 0; j < seenCount; j++) {
            if (seen[j] == hash) {
                char *result = (char *) malloc(sizeof(char) * (length + 1));
                strncpy(result, s + i, length);
                result[length] = '\0';
                free(seen);
                return result;
            }
        }
        seen[seenCount++] = hash;
    }
    free(seen);
    return "";
}