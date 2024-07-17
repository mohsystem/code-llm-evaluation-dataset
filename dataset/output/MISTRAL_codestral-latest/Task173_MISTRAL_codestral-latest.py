def longest_dup_substring(s):
    def search(L):
        seen = set()
        for i in range(len(s) - L + 1):
            curr = s[i:i+L]
            if curr in seen:
                return i
            seen.add(curr)
        return -1

    left, right = 1, len(s)
    start = -1
    while left <= right:
        mid = left + (right - left) // 2
        pos = search(mid)
        if pos != -1:
            left = mid + 1
            start = pos
        else:
            right = mid - 1
    return s[start:start+left-1] if start != -1 else ""