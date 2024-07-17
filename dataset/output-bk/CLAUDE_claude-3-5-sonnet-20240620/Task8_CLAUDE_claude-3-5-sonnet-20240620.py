
def find_missing_letter(chars):
    for i in range(len(chars) - 1):
        if ord(chars[i + 1]) - ord(chars[i]) > 1:
            return chr(ord(chars[i]) + 1)
    return \' \'

print(find_missing_letter([\'a\',\'b\',\'c\',\'d\',\'f\']))
print(find_missing_letter([\'O\',\'Q\',\'R\',\'S\']))
