def accum(s):
  return '-'.join((c * (i + 1)).title() for i, c in enumerate(s))

print(accum("abcd"))
print(accum("RqaEzty"))
print(accum("cwAt"))