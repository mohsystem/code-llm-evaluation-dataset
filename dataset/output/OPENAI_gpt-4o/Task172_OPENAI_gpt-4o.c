#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool contains(char** seen, int seenSize, char* sub) {
    for (int i = 0; i < seenSize; i++) {
        if (strcmp(seen[i], sub) == 0) {
            return true;
        }
    }
    return false;
}

void addToSeen(char*** seen, int* seenSize, char* sub) {
    (*seen)[*seenSize] = (char*)malloc((strlen(sub) + 1) * sizeof(char));
    strcpy((*seen)[*seenSize], sub);
    (*seenSize)++;
}

int distinctConcatenations(const char* text) {
    int length = strlen(text);
    char** seen = (char**)malloc(length * sizeof(char*));
    int seenSize = 0;

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j <= length; j++) {
            int subLen = j - i;
            char* sub = (char*)malloc((subLen + 1) * sizeof(char));
            strncpy(sub, text + i, subLen);
            sub[subLen] = '\0';

            if (subLen % 2 == 0) {
                int halfLen = subLen / 2;
                char* firstHalf = (char*)malloc((halfLen + 1) * sizeof(char));
                char* secondHalf = (char*)malloc((halfLen + 1) * sizeof(char));
                strncpy(firstHalf, sub, halfLen);
                firstHalf[halfLen] = '\0';
                strncpy(secondHalf, sub + halfLen, halfLen);
                secondHalf[halfLen] = '\0';

                if (strcmp(firstHalf, secondHalf) == 0 && !contains(seen, seenSize, sub)) {
                    addToSeen(&seen, &seenSize, sub);
                }

                free(firstHalf);
                free(secondHalf);
            }
            free(sub);
        }
    }

    for (int i = 0; i < seenSize; i++) {
        free(seen[i]);
    }
    free(seen);

    return seenSize;
}

int main() {
    printf("%d
", distinctConcatenations("abcabcabc")); // Output: 3
    printf("%d
", distinctConcatenations("leetcodeleetcode")); // Output: 2
    return 0;
}