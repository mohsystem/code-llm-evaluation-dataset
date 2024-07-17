#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 30001
#define MOD 1000000007

int parent[MAX_SIZE];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_set(int x, int y) {
    parent[find(x)] = find(y);
}

char* longestDupSubstring(char* s) {
    int n = strlen(s);
    int left = 1, right = n;
    int start = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int pos = search(s, mid);
        if (pos != -1) {
            left = mid + 1;
            start = pos;
        } else {
            right = mid - 1;
        }
    }
    if (start != -1) {
        char* result = (char*)malloc((left - 1) * sizeof(char));
        strncpy(result, s + start, left - 1);
        result[left - 1] = '\0';
        return result;
    }
    return "";
}

int search(char* s, int L) {
    int n = strlen(s);
    int mod = pow(26, L);
    int a = 26;
    int h = 0;
    for (int i = 0; i < L; i++) {
        h = (h * a + (s[i] - 'a')) % mod;
    }
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = L; i < n; i++) {
        h = (h * a - (s[i - L] - 'a') * pow(a, L) + (s[i] - 'a')) % mod;
        int j = find(h);
        if (j >= i - L) {
            return i - L + 1;
        }
        union_set(h, i - L + 1);
    }
    return -1;
}