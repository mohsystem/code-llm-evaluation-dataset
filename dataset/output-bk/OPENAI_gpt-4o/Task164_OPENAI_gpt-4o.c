#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *nameA = *((char **)a);
    char *nameB = *((char **)b);
    
    char *lastNameA = strrchr(nameA, ' ') + 1;
    char *lastNameB = strrchr(nameB, ' ') + 1;
    
    int lenA = strlen(lastNameA);
    int lenB = strlen(lastNameB);
    
    if (lenA != lenB) {
        return lenA - lenB;
    }
    return strcmp(lastNameA, lastNameB);
}

void lastNameLensort(char *names[], int n) {
    qsort(names, n, sizeof(char *), compare);
}

int main() {
    char *names[] = {
        "Jennifer Figueroa",
        "Heather Mcgee",
        "Amanda Schwartz",
        "Nicole Yoder",
        "Melissa Hoffman"
    };
    
    int n = sizeof(names) / sizeof(names[0]);
    
    lastNameLensort(names, n);
    
    for (int i = 0; i < n; i++) {
        printf("%s
", names[i]);
    }
    
    return 0;
}