
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        n = len(text)
        result = set()
        
        for i in range(n):
            for length in range(1, (n - i) // 2 + 1):
                if text[i:i+length] == text[i+length:i+2*length]:
                    result.add(text[i:i+2*length])
        
        return len(result)
