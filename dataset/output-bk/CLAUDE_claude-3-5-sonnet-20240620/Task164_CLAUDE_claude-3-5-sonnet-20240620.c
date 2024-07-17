
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NAMES 100

int compare(const void* a, const void* b) {
    const char* nameA = *(const char**)a;
    const char* nameB = *(const char**)b;
    
    const char* lastNameA = strrchr(nameA, \' \') + 1;
    const char* lastNameB = strrchr(nameB, \' \') + 1;
    
    int lenA = strlen(lastNameA);
    int lenB = strlen(lastNameB);
    
    if (lenA != lenB) {
        return lenA - lenB;
    }
    
    return strcmp(lastNameA, lastNameB);
}

void lastNameLenSort(char names[][MAX_NAME_LENGTH], int n) {
    char* ptrs[MAX_NAMES];
    for (int i = 0; i < n; i++) {
        ptrs[i] = names[i];
    }
    
    qsort(ptrs, n, sizeof(char*), compare);
    
    for (int i = 0; i < n; i++) {
        strcpy(names[i], ptrs[i]);
    }
}

int main() {
    char names[MAX_NAMES][MAX_NAME_LENGTH] = {
        "Jennifer Figueroa",
        "Heather Mcgee",
        "Amanda Schwartz",
        "Nicole Yoder",
        "Melissa Hoffman"
    };
    int n = 5;
    
    lastNameLenSort(names, n);
    
    for (int i = 0; i < n; i++) {
        printf("%s\
", names[i]);
    }
    
    return 0;
}
