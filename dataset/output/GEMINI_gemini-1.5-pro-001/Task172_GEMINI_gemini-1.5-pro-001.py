def distinct_echo_substrings(text):
    n = len(text)
    seen = set()
    for i in range(n):
        for j in range(i + 1, n + 1, 2):
            sub = text[i:j]
            if sub[: (j - i) // 2] == sub[(j - i) // 2:]:
                seen.add(sub)
    return len(seen)