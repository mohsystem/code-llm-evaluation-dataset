#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    char* token = strtok(s, " ");
    char* result = malloc(strlen(s) + 1);
    result[0] = '\0';
    while (token != NULL) {
        if (strlen(token) >= 5) {
            reverse(token);
        }
        strcat(result, token);
        strcat(result, " ");
        token = strtok(NULL, " ");
    }
    result[strlen(result) - 1] = '\0';
    return result;
}

int main() {
    char s1[] = "Hey fellow warriors";
    char s2[] = "This is a test";
    char s3[] = "This is another test";
    printf("%s\n", reverseWords(s1));
    printf("%s\n", reverseWords(s2));
    printf("%s\n", reverseWords(s3));
    return 0;
}