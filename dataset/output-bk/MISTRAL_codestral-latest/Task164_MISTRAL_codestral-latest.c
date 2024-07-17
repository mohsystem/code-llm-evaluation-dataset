#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    const char** strA = (const char**)a;
    const char** strB = (const char**)b;
    char lastNameA[50], lastNameB[50];
    sscanf(*strA, "%*s %s", lastNameA);
    sscanf(*strB, "%*s %s", lastNameB);
    int lenDiff = strlen(lastNameA) - strlen(lastNameB);
    if (lenDiff != 0) {
        return lenDiff;
    } else {
        return strcmp(lastNameA, lastNameB);
    }
}

void lastNameLenSort(char* names[], int n) {
    qsort(names, n, sizeof(char*), compare);
}

int main() {
    char* names[] = {"Jennifer Figueroa", "Heather Mcgee", "Amanda Schwartz", "Nicole Yoder", "Melissa Hoffman"};
    int n = sizeof(names) / sizeof(names[0]);
    lastNameLenSort(names, n);
    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
    }
    return 0;
}