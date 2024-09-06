def longest_dup_substring(s):
    n = len(s)
    nums = [ord(c) - ord('a') for c in s]
    a = 26
    mod = 2**32

    def check(length):
        h = 0
        for i in range(length):
            h = (h * a + nums[i]) % mod
        seen = {h}
        aL = pow(a, length, mod)
        for start in range(1, n - length + 1):
            h = (h * a - nums[start - 1] * aL + nums[start + length - 1]) % mod
            if h in seen:
                return start
            seen.add(h)
        return -1

    start, length = -1, 0
    for k in range(1, n):
        pos = check(k)
        if pos != -1 and k > length:
            start = pos
            length = k
    return s[start:start + length] if start != -1 else ""