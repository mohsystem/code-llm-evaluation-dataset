
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* high(const char* s) {
    char* copy = strdup(s);
    char* token = strtok(copy, " ");
    int maxScore = 0;
    char* maxWord = NULL;
    
    while (token != NULL) {
        int score = 0;
        for (int i = 0; token[i]; i++) {
            score += token[i] - 'a' + 1;
        }
        if (score > maxScore) {
            maxScore = score;
            maxWord = token;
        }
        token = strtok(NULL, " ");
    }
    
    char* result = strdup(maxWord);
    free(copy);
    return result;
}

int main() {
    printf("%s\\n", high("man i need a taxi up to ubud")); // Output: taxi
    printf("%s\\n", high("what time are we climbing up the volcano")); // Output: volcano
    printf("%s\\n", high("take me to semynak")); // Output: semynak
    return 0;
}
