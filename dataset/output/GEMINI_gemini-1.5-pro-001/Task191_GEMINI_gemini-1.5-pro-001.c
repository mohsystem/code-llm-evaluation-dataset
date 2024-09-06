int longestValidParentheses(char * s){
    int maxLen = 0;
    int *stack = (int*)malloc(sizeof(int) * (strlen(s) + 1));
    int top = -1;
    stack[++top] = -1; // Initialize with a sentinel
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(') {
            stack[++top] = i;
        } else {
            --top;
            if (top == -1) {
                stack[++top] = i;
            } else {
                maxLen = (maxLen > i - stack[top]) ? maxLen : (i - stack[top]);
            }
        }
    }
    free(stack);
    return maxLen;
}