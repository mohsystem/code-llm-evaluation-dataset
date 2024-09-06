// C code for finding length of the longest valid parentheses substring

#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int stack[30000];
    int stackIndex = 0;
    stack[stackIndex++] = -1;
    int max_length = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[stackIndex++] = i;
        } else {
            stackIndex--;
            if (stackIndex == 0) {
                stack[stackIndex++] = i;
            } else {
                int current_length = i - stack[stackIndex - 1];
                if (current_length > max_length) {
                    max_length = current_length;
                }
            }
        }
    }

    return max_length;
}

int main() {
    char s[] = "(()";  // Example 1
    printf("%d\n", longestValidParentheses(s));  // Output: 2
    char s2[] = ")()())";  // Example 2
    printf("%d\n", longestValidParentheses(s2));  // Output: 4
    char s3[] = "";  // Example 3
    printf("%d\n", longestValidParentheses(s3));  // Output: 0
    return 0;
}