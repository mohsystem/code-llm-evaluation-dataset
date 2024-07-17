#include <string.h>
#include <stdio.h>

char* longestDupSubstring(char* s) {
    int lo = 1, hi = strlen(s);
    char* ans = "";
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        char* tmp = search(s, mid);
        if (tmp != "") {
            ans = tmp;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

char* search(char* s, int L) {
    char* seen[10000];
    int seenIndex = 0;
    for (int i = 0; i <= strlen(s) - L; i++) {
        char tmp[L + 1];
        strncpy(tmp, s + i, L);
        tmp[L] = '\0';
        int found = 0;
        for (int j = 0; j < seenIndex; j++) {
            if (strcmp(tmp, seen[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            return tmp;
        }
        strcpy(seen[seenIndex], tmp);
        seenIndex++;
    }
    return "";
}