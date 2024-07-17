#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int stack[30000], top = -1;
    stack[++top] = -1;
    int maxLength = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int length = i - stack[top];
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }
    return maxLength;
}

int main() {
    printf("%d
", longestValidParentheses("(()"));
    printf("%d
", longestValidParentheses(")()())"));
    printf("%d
", longestValidParentheses(""));
    return 0;
}