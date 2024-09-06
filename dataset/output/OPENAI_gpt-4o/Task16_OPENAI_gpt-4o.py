def solution(str, ending):
    return str.endswith(ending)

print(solution('abc', 'bc'))  # returns true
print(solution('abc', 'd'))    # returns false