def solution(string, ending):
    return string.endswith(ending)

print(solution("abc", "bc"))  # True
print(solution("abc", "d"))   # False