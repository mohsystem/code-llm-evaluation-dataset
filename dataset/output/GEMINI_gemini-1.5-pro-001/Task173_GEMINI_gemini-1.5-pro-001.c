#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b, void *s) {
    return strcmp((char *)s + *(int *)a, (char *)s + *(int *)b);
}

char * longestDupSubstring(char * s){
    int n = strlen(s);
    int *sa = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
    }
    qsort_r(sa, n, sizeof(int), cmp, s);

    int *lcp = (int *)malloc(n * sizeof(int));
    for (int i = 1; i < n; ++i) {
        int len = 0;
        while (sa[i] + len < n && sa[i - 1] + len < n && s[sa[i] + len] == s[sa[i - 1] + len]) {
            ++len;
        }
        lcp[i] = len;
    }

    int start = 0;
    int maxlen = 0;
    for (int i = 1; i < n; ++i) {
        if (lcp[i] > maxlen) {
            maxlen = lcp[i];
            start = sa[i];
        }
    }

    free(sa);
    free(lcp);

    if (maxlen > 0) {
        char *ret = (char *)malloc((maxlen + 1) * sizeof(char));
        strncpy(ret, s + start, maxlen);
        ret[maxlen] = '\0';
        return ret;
    } else {
        return "";
    }
}