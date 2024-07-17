def XO(s):
    return s.lower().count('x') == s.lower().count('o')

print(XO("ooxx"))
print(XO("xooxx"))
print(XO("ooxXm"))
print(XO("zpzpzpp"))
print(XO("zzoo"))