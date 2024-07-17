#include <stdio.h>
#include <string.h>

void reverseWords(char* str) {
    char* token = strtok(str, " ");
    while (token != NULL) {
        if (strlen(token) >= 5) {
            int start = 0;
            int end = strlen(token) - 1;
            while (start < end) {
                char temp = token[start];
                token[start] = token[end];
                token[end] = temp;
                start++;
                end--;
            }
        }
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("
");
}

int main() {
    char str1[] = "Hey fellow warriors";
    char str2[] = "This is a test";
    char str3[] = "This is another test";
    reverseWords(str1);
    reverseWords(str2);
    reverseWords(str3);
    return 0;
}