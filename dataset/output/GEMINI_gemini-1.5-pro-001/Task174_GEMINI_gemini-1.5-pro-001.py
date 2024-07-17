class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        base, mod = 26, 10**9 + 7
        hash_val, pow_base = 0, 1
        best = 0
        for i in range(n - 1, -1, -1):
            hash_val = (hash_val * base + ord(s[i]) - ord('a')) % mod
            if hash_val == (ord(s[i]) - ord('a')) * pow_base % mod:
                best = i
            pow_base = (pow_base * base) % mod
        return s[best + 1:][::-1] + s