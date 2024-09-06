def longestDupSubstring(s):
    n = len(s)
    def check(length):
        seen = set()
        for i in range(n - length + 1):
            substring = s[i:i + length]
            if substring in seen:
                return substring
            seen.add(substring)
        return ""
    left, right = 1, n
    result = ""
    while left <= right:
        mid = left + (right - left) // 2
        substring = check(mid)
        if substring:
            result = substring
            left = mid + 1
        else:
            right = mid - 1
    return result