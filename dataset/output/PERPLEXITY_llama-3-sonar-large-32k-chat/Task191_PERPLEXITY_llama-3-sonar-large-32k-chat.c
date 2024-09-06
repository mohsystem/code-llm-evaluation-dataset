#include <string.h>

int longestValidParentheses(char *s) {
    int max_len = 0;
    int last_invalid = -1;
    int stack[10000];
    int top = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            if (top == -1) {
                last_invalid = i;
            } else {
                top--;
                if (top == -1) {
                    max_len = max_len > i - last_invalid ? max_len : i - last_invalid;
                } else {
                    max_len = max_len > i - stack[top] ? max_len : i - stack[top];
                }
            }
        }
    }
    return max_len;
}