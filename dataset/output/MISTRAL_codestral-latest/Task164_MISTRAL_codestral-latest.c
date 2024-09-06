#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastNameLen(const char *name) {
    const char *last = strrchr(name, ' ');
    if (last != NULL) {
        return strlen(last + 1);
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    int lenDiff = lastNameLen(*ia) - lastNameLen(*ib);
    if (lenDiff != 0) {
        return lenDiff;
    } else {
        return strcmp(*ia, *ib);
    }
}

void lastNameLenSort(char *names[], int n) {
    qsort(names, n, sizeof(char *), cmp);
}

int main() {
    char *names[] = {"Jennifer Figueroa", "Heather Mcgee", "Amanda Schwartz", "Nicole Yoder", "Melissa Hoffman"};
    int n = sizeof(names) / sizeof(names[0]);
    lastNameLenSort(names, n);
    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
    }
    return 0;
}