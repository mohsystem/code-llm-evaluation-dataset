def solution(str1, str2):
    return str1.endswith(str2)

print(solution("abc", "bc")) # returns True
print(solution("abc", "d")) # returns False