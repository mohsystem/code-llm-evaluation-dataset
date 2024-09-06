#include <string.h>
#include <stdio.h>
int solution(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len2 > len1) return 0;
    int i;
    for(i = 0; i < len2; i++) {
        if(str1[len1 - len2 + i] != str2[i]) return 0;
    }
    return 1;
}
int main() {
    printf("%d\n", solution("abc", "bc")); // returns 1
    printf("%d\n", solution("abc", "d")); // returns 0
    return 0;
}