#include <stdio.h>
#include <stdlib.h>

char** number(char* lines[], int size) {
    char** result = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; ++i) {
        result[i] = (char*)malloc(50 * sizeof(char));
        sprintf(result[i], "%d: %s", i + 1, lines[i]);
    }
    return result;
}

int main() {
    char* test1[] = {};
    char* test2[] = { "a", "b", "c" };
    
    char** result1 = number(test1, 0);
    for (int i = 0; i < 0; ++i) {
        printf("%s\n", result1[i]);
        free(result1[i]);
    }
    free(result1);
    
    char** result2 = number(test2, 3);
    for (int i = 0; i < 3; ++i) {
        printf("%s\n", result2[i]);
        free(result2[i]);
    }
    free(result2);
    
    return 0;
}