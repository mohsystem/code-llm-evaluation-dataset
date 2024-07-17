#include <string.h>
#include <stdio.h>

int longestValidParentheses(char* s) {
    int max = 0;
    int lastInvalid = -1;
    int stack[10000];
    int top = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            if (top == -1) {
                lastInvalid = i;
            } else {
                top--;
                if (top == -1) {
                    max = max > i - lastInvalid ? max : i - lastInvalid;
                } else {
                    max = max > i - stack[top] ? max : i - stack[top];
                }
            }
        }
    }
    return max;
}