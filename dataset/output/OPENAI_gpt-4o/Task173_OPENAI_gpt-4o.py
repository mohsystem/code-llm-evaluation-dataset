# Python code
from collections import defaultdict

def longestDupSubstring(s):
    def roll_hash(s, length):
        p = 31
        m = 2**61 - 1
        hash_value = 0
        p_pow = 1
        for i in range(length):
            hash_value = (hash_value + (ord(s[i]) - ord('a') + 1) * p_pow) % m
            p_pow = (p_pow * p) % m
        return hash_value
    
    def search_substring(s, length):
        hashes = defaultdict(list)
        p = 31
        m = 2**61 - 1
        p_pow = pow(p, length - 1, m)
        curr_hash = roll_hash(s, length)
        hashes[curr_hash].append(0)
        
        for i in range(1, len(s) - length + 1):
            curr_hash = (curr_hash - (ord(s[i - 1]) - ord('a') + 1)) % m
            curr_hash = (curr_hash * p + (ord(s[i + length - 1]) - ord('a') + 1)) % m
            if curr_hash in hashes:
                for start in hashes[curr_hash]:
                    if s[start:start+length] == s[i:i+length]:
                        return s[start:start+length]
            hashes[curr_hash].append(i)
        return ""
    
    left, right, result = 1, len(s) - 1, ""
    while left <= right:
        mid = left + (right - left) // 2
        substring = search_substring(s, mid)
        if substring:
            result = substring
            left = mid + 1
        else:
            right = mid - 1
    return result

# Example usage:
print(longestDupSubstring("banana"))  # Output: "ana"
print(longestDupSubstring("abcd"))    # Output: ""