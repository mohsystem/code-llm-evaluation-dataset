
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def rabin_karp(length):
            q = (1 << 31) - 1
            h = 0
            for i in range(length):
                h = (h * 26 + ord(s[i]) - ord('a')) % q
            
            seen = {h}
            aL = pow(26, length, q)
            for start in range(1, len(s) - length + 1):
                h = (h * 26 - (ord(s[start-1]) - ord('a')) * aL + ord(s[start+length-1]) - ord('a')) % q
                if h in seen:
                    return s[start:start+length]
                seen.add(h)
            
            return None
        
        left, right = 0, len(s)
        result = ""
        while left < right:
            mid = left + (right - left) // 2
            candidate = rabin_karp(mid)
            if candidate:
                left = mid + 1
                result = candidate
            else:
                right = mid
        
        return result
