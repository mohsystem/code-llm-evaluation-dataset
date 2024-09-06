
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int* stack = (int*)malloc((len + 1) * sizeof(int));
    int top = 0;
    int maxLength = 0;
    
    stack[top++] = -1;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[top++] = i;
        } else {
            top--;
            if (top == 0) {
                stack[top++] = i;
            } else {
                maxLength = MAX(maxLength, i - stack[top - 1]);
            }
        }
    }
    
    free(stack);
    return maxLength;
}

int main() {
    printf("%d\\n", longestValidParentheses("(()"));  // Output: 2
    printf("%d\\n", longestValidParentheses(")()())"));  // Output: 4
    printf("%d\\n", longestValidParentheses(""));  // Output: 0
    return 0;
}
