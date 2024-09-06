s = "aacecaaa"
# Function to find the shortest palindrome by adding characters in front of the string
def shortest_palindrome(s):
    rev_s = s[::-1]
    for i in range(len(s) + 1):
        if s.startswith(rev_s[i:]):
            return rev_s[:i] + s

print(shortest_palindrome(s))