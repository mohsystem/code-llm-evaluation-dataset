def dig_pow(n, p):
    s = 0
    for i, c in enumerate(str(n)):
        s += pow(int(c), p+i)
    return s/n if s%n==0 else -1