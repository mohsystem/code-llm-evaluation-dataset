
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NAMES 100

int compare(const void* a, const void* b) {
    const char* nameA = *(const char**)a;
    const char* nameB = *(const char**)b;
    
    const char* lastA = strrchr(nameA, ' ') + 1;
    const char* lastB = strrchr(nameB, ' ') + 1;
    
    int lenA = strlen(lastA);
    int lenB = strlen(lastB);
    
    if (lenA != lenB) {
        return lenA - lenB;
    }
    return strcmp(lastA, lastB);
}

void lastNameLensort(char** names, int size) {
    qsort(names, size, sizeof(char*), compare);
}

int main() {
    char* names[MAX_NAMES] = {
        "Jennifer Figueroa",
        "Heather Mcgee",
        "Amanda Schwartz",
        "Nicole Yoder",
        "Melissa Hoffman"
    };
    int size = 5;
    
    lastNameLensort(names, size);
    
    for (int i = 0; i < size; i++) {
        printf("%s\\n", names[i]);
    }
    
    return 0;
}
