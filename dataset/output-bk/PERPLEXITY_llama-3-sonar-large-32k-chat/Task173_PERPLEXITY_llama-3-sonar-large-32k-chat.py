def longestDupSubstring(s: str) -> str:
    def search(L):
        seen = set()
        for i in range(len(s) - L + 1):
            tmp = s[i:i + L]
            if tmp in seen:
                return tmp
            seen.add(tmp)
        return ""

    lo, hi = 1, len(s)
    ans = ""
    while lo <= hi:
        mid = (lo + hi) // 2
        tmp = search(mid)
        if tmp != "":
            ans = tmp
            lo = mid + 1
        else:
            hi = mid - 1
    return ans