#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    char** s1 = (char**)a;
    char** s2 = (char**)b;
    char* token1 = strtok(*s1, " ");
    token1 = strtok(NULL, " ");
    char* token2 = strtok(*s2, " ");
    token2 = strtok(NULL, " ");
    if (strlen(token1) != strlen(token2)) {
        return strlen(token1) - strlen(token2);
    } else {
        return strcmp(token1, token2);
    }
}

int main() {
    char* names[] = {
      "Jennifer Figueroa",
      "Heather Mcgee",
      "Amanda Schwartz",
      "Nicole Yoder",
      "Melissa Hoffman"
    };
    qsort(names, 5, sizeof(char*), compare);
    for (int i = 0; i < 5; i++) {
        printf("%s
", names[i]);
    }
    return 0;
}