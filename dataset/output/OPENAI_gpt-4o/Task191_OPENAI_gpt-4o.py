# Python code for finding length of the longest valid parentheses substring

def longestValidParentheses(s):
    stack = [-1]
    max_length = 0
    
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            stack.pop()
            if len(stack) == 0:
                stack.append(i)
            else:
                max_length = max(max_length, i - stack[-1])
    
    return max_length

if __name__ == "__main__":
    s = "(()"  # Example 1
    print(longestValidParentheses(s))  # Output: 2
    s = ")()())"  # Example 2
    print(longestValidParentheses(s))  # Output: 4
    s = ""  # Example 3
    print(longestValidParentheses(s))  # Output: 0