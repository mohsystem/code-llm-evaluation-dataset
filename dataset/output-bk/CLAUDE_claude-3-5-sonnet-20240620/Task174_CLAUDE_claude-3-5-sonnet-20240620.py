
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        rev = s[::-1]
        temp = s + "#" + rev
        lps = [0] * len(temp)
        
        length = 0
        i = 1
        while i < len(temp):
            if temp[i] == temp[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        
        return rev[:-lps[-1]] + s
