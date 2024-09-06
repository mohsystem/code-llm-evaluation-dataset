def repeatedSubstringPattern(s):
    n = len(s)
    for i in range(1, n // 2 + 1):
        if n % i == 0 and s[:i] * (n // i) == s:
            return True
    return False

def numDistinct(text):
    n = len(text)
    count = 0
    for i in range(1, n // 2 + 1):
        if repeatedSubstringPattern(text[:i]):
            count += 1
    return count

text = "abcabcabc"
print(numDistinct(text))