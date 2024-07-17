def accum(s):
    result = ''
    for i in range(len(s)):
        if i > 0:
            result += '-'
        result += s[i].upper() + s[i].lower() * i
    return result