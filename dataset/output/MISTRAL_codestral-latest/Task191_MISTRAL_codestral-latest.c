#include <stdio.h>
#include <stdlib.h>

int longestValidParentheses(char *s) {
    int *stack = (int *)malloc(sizeof(int) * (strlen(s) + 1));
    int top = -1;
    stack[++top] = -1;
    int maxLength = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            if (top > 0) {
                top--;
                maxLength = fmax(maxLength, i - stack[top]);
            } else {
                stack[++top] = i;
            }
        }
    }
    free(stack);
    return maxLength;
}