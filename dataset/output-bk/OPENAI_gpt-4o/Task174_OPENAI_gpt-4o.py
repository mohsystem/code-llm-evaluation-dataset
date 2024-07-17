def shortest_palindrome(s: str) -> str:
    if len(s) == 0: return s
    rev_s = s[::-1]
    for i in range(len(s) + 1):
        if s.startswith(rev_s[i:]):
            return rev_s[:i] + s
    return ""

s1 = "aacecaaa"
s2 = "abcd"
print(shortest_palindrome(s1))  # Output: aaacecaaa
print(shortest_palindrome(s2))  # Output: dcbabcd