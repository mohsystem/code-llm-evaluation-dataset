def xo(s):
    return s.lower().count('x') == s.lower().count('o')

print(xo("ooxx")) # True
print(xo("xooxx")) # False
print(xo("ooxXm")) # True
print(xo("zpzpzpp")) # True
print(xo("zzoo")) # False