def longest_valid_parentheses(s):
    stack = [-1]
    max_length = 0
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            stack.pop()
            if len(stack) != 0:
                max_length = max(max_length, i - stack[-1])
            else:
                stack.append(i)
    return max_length