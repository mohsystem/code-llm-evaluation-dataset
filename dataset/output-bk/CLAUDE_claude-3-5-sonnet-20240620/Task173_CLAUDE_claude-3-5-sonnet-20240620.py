
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def rabin_karp(mid):
            p = pow(26, mid, mod)
            cur = 0
            for i in range(mid):
                cur = (cur * 26 + ord(s[i]) - ord(\'a\')) % mod
            
            seen = {cur}
            for i in range(mid, len(s)):
                cur = (cur * 26 - (ord(s[i-mid]) - ord(\'a\')) * p + ord(s[i]) - ord(\'a\')) % mod
                if cur in seen:
                    return s[i-mid+1:i+1]
                seen.add(cur)
            return ""

        mod = 2**63 - 1
        left, right = 0, len(s)
        res = ""
        while left < right:
            mid = left + (right - left) // 2
            candidate = rabin_karp(mid)
            if candidate:
                left = mid + 1
                res = candidate
            else:
                right = mid
        return res
