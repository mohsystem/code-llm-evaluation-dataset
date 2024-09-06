def distinctEchoSubstrings(text):
    n = len(text)
    res = set()
    for i in range(n):
        for j in range(i + 1, n + 1):
            s = text[i:j]
            if s == s[::-1]:
                res.add(s)
    return len(res)