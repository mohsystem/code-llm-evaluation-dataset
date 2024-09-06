def longestDupSubstring(s: str) -> str:
    def search(L):
        seen = set()
        for i in range(len(s) - L + 1):
            tmp = s[i:i + L]
            if tmp in seen:
                return tmp
            seen.add(tmp)
        return ""
    left, right = 1, len(s)
    ans = ""
    while left <= right:
        mid = (left + right) // 2
        tmp = search(mid)
        if tmp != "":
            ans = tmp
            left = mid + 1
        else:
            right = mid - 1
    return ans