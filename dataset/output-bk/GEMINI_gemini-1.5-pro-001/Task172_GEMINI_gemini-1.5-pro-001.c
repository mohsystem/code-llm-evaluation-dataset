#include <stdio.h>
#include <string.h>

int distinctEchoSubstrings(char *text) {
    int n = strlen(text);
    char substrings[1000][1000];
    int count = 0;
    int found;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j += 2) {
            char sub[1000];
            strncpy(sub, text + i, j - i);
            sub[j - i] = '\0';
            if (strncmp(sub, sub + (j - i) / 2, (j - i) / 2) == 0) {
                found = 0;
                for (int k = 0; k < count; k++) {
                    if (strcmp(substrings[k], sub) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(substrings[count++], sub);
                }
            }
        }
    }
    return count;
}