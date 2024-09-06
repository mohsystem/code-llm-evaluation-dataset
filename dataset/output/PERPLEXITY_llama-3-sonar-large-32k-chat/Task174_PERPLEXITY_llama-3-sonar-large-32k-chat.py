def shortestPalindrome(s: str) -> str:
    a = s + "#" + s[::-1]
    k = [0]
    for i in range(1, len(a)):
        j = k[i-1]
        while j > 0 and a[i] != a[j]:
            j = k[j-1]
        k.append(j + (a[i] == a[j]))
    return s[k[-1]:][::-1] + s