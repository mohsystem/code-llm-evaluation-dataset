#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int distinctEchoSubstrings(char * text){
    int n = strlen(text);
    char **substrings = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        substrings[i] = (char *)malloc(n * sizeof(char));
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            char *substring = (char *)malloc((len + 1) * sizeof(char));
            strncpy(substring, text + i, len);
            substring[len] = '\0';

            if (len % 2 == 0 && strncmp(substring, substring + len / 2, len / 2) == 0) {
                int duplicate = 0;
                for (int j = 0; j < count; j++) {
                    if (strcmp(substring, substrings[j]) == 0) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    strcpy(substrings[count++], substring);
                }
            }
            free(substring);
        }
    }
    for (int i = 0; i < n; i++) {
        free(substrings[i]);
    }
    free(substrings);
    return count;
}