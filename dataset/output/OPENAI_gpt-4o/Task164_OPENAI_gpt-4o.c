#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char first[50];
    char last[50];
} Name;

int compare(const void *a, const void *b) {
    Name *nameA = (Name *)a;
    Name *nameB = (Name *)b;
    if (strlen(nameA->last) == strlen(nameB->last)) {
        return strcmp(nameA->last, nameB->last);
    }
    return strlen(nameA->last) - strlen(nameB->last);
}

void lastNameLensort(Name names[], int n) {
    qsort(names, n, sizeof(Name), compare);
}

int main() {
    Name names[] = {{"Jennifer", "Figueroa"}, {"Heather", "Mcgee"}, {"Amanda", "Schwartz"}, {"Nicole", "Yoder"}, {"Melissa", "Hoffman"}};
    int n = sizeof(names) / sizeof(names[0]);
    lastNameLensort(names, n);

    for (int i = 0; i < n; i++) {
        printf("%s %s\n", names[i].first, names[i].last);
    }
    return 0;
}