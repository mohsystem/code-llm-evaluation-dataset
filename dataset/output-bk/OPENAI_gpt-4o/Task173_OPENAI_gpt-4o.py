def longest_dup_substring(s):
    def search(length):
        seen = set()
        for i in range(len(s) - length + 1):
            current = s[i:i + length]
            if current in seen:
                return current
            seen.add(current)
        return None

    res, left, right = "", 1, len(s) - 1
    while left <= right:
        mid = (left + right) // 2
        dup = search(mid)
        if dup:
            res, left = dup, mid + 1
        else:
            right = mid - 1
    return res

  
s1 = "banana"
s2 = "abcd"
print(longest_dup_substring(s1))  # Output: "ana"
print(longest_dup_substring(s2))  # Output: ""