class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        n = len(text)
        s = set()
        for i in range(n):
            for j in range(i + 1, n + 1):
                sub = text[i:j]
                if len(sub) % 2 == 0 and sub[:len(sub) // 2] == sub[len(sub) // 2:]:
                    s.add(sub)
        return len(s)