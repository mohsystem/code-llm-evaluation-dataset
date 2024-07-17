def longestValidParentheses(s):
    stack = []
    max_len = 0
    last_invalid = -1
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            if not stack:
                last_invalid = i
            else:
                stack.pop()
                if not stack:
                    max_len = max(max_len, i - last_invalid)
                else:
                    max_len = max(max_len, i - stack[-1])
    return max_len