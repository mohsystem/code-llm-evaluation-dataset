
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30001

int longestValidParentheses(char* s) {
    int stack[MAX_SIZE];
    int top = 0;
    int maxLength = 0;
    int len = strlen(s);
    
    stack[top++] = -1;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == \'(\') {
            stack[top++] = i;
        } else {
            top--;
            if (top == 0) {
                stack[top++] = i;
            } else {
                int currentLength = i - stack[top - 1];
                maxLength = (currentLength > maxLength) ? currentLength : maxLength;
            }
        }
    }
    
    return maxLength;
}

int main() {
    char s[MAX_SIZE];
    scanf("%s", s);
    printf("%d\
", longestValidParentheses(s));
    return 0;
}
