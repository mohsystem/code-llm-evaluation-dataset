#include <stdio.h>
#include <string.h>

void tweakLetters(char s[], int tweaks[], char result[]) {
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i] + tweaks[i];
        if (c < 'a') {
            c += 26;
        } else if (c > 'z') {
            c -= 26;
        }
        result[i] = c;
    }
    result[strlen(s)] = '\0';
}

int main() {
    char s1[] = "apple";
    int tweaks1[] = {0, 1, -1, 0, -1};
    char result1[6];
    tweakLetters(s1, tweaks1, result1);
    printf("%s
", result1); // "aqold"

    char s2[] = "many";
    int tweaks2[] = {0, 0, 0, -1};
    char result2[5];
    tweakLetters(s2, tweaks2, result2);
    printf("%s
", result2); // "manx"

    char s3[] = "rhino";
    int tweaks3[] = {1, 1, 1, 1, 1};
    char result3[6];
    tweakLetters(s3, tweaks3, result3);
    printf("%s
", result3); // "sijop"
    return 0;
}