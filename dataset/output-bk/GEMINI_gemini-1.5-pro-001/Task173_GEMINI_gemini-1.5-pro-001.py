def longestDupSubstring(s):
    n = len(s)
    sa = sorted(range(n), key=lambda i: s[i:])
    lcp = [0] * n
    for i in range(1, n):
        lcp[i] = 0
        while sa[i] + lcp[i] < n and sa[i - 1] + lcp[i] < n and s[sa[i] + lcp[i]] == s[sa[i - 1] + lcp[i]]:
            lcp[i] += 1

    start = 0
    length = 0
    for i in range(1, n):
        if lcp[i] > length:
            length = lcp[i]
            start = sa[i]

    if length > 0:
        return s[start : start + length]
    else:
        return ""