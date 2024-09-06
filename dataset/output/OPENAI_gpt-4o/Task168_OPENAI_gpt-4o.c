#include <stdio.h>
#include <string.h>

void tweakLetters(const char* s, const int* arr, char* result) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; ++i) {
        result[i] = (char)(((s[i] - 'a' + arr[i]) % 26 + 26) % 26 + 'a');
    }
    result[len] = '\0';
}

int main() {
    char result1[10], result2[10], result3[10];
    tweakLetters("apple", (int[]){0, 1, -1, 0, -1}, result1);
    tweakLetters("many", (int[]){0, 0, 0, -1}, result2);
    tweakLetters("rhino", (int[]){1, 1, 1, 1, 1}, result3);
    
    printf("%s\n", result1);  // "aqold"
    printf("%s\n", result2);  // "manx"
    printf("%s\n", result3);  // "sijop"
    
    return 0;
}