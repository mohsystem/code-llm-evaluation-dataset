def accum(s):
    return '-'.join((c * (i + 1)).capitalize() for i, c in enumerate(s))