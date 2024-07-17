def accum(s):
    return '-'.join(c.upper() + c.lower() * i for i, c in enumerate(s))

print(accum("abcd"))
print(accum("RqaEzty"))
print(accum("cwAt"))