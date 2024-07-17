#include <string.h>
#include <stdio.h>

int solution(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2) return 0;
    return strcmp(str1 + len1 - len2, str2) == 0;
}

int main() {
    printf("%d
", solution("abc", "bc")); // returns 1
    printf("%d
", solution("abc", "d")); // returns 0
    return 0;
}