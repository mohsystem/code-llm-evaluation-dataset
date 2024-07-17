#include <stdio.h>
#include <string.h>

char* search(char* s, int length, char* buffer) {
    int n = strlen(s);
    for (int i = 0; i + length <= n; ++i) {
        strncpy(buffer, s + i, length);
        buffer[length] = '\0';
        for (int j = i+1; j + length <= n; ++j) {
            if (strncmp(buffer, s + j, length) == 0) {
                return buffer;
            }
        }
    }
    return NULL;
}

char* longestDupSubstring(char* s) {
    int left = 1, right = strlen(s) - 1;
    static char res[30000];
    static char buffer[30000];
    res[0] = '\0';
    while (left <= right) {
        int mid = (left + right) / 2;
        char* dup = search(s, mid, buffer);
        if (dup != NULL) {
            strcpy(res, dup);
            left = mid + 1;
        } else {
            right = mid - 1;
    }
  }
  return res;
}

int main() {
    char s1[] = "banana";
    char s2[] = "abcd";
    printf("%s
", longestDupSubstring(s1)); // Output: "ana"
    printf("%s
", longestDupSubstring(s2)); // Output: ""
    return 0;
}