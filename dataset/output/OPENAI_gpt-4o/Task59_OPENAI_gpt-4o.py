def accum(s):
    return '-'.join((c * (i + 1)).capitalize() for i, c in enumerate(s))

print(accum("abcd"))   # Output: A-Bb-Ccc-Dddd
print(accum("RqaEzty"))  # Output: R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy
print(accum("cwAt"))   # Output: C-Ww-Aaa-Tttt