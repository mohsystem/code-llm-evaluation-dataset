def expanded_form(num):
    num_str = str(num)
    length = len(num_str)
    result = []
    for index, digit in enumerate(num_str):
        if digit != '0':
            result.append(digit + '0' * (length - index - 1))
    return ' + '.join(result)

print(expanded_form(12))   # Should return "10 + 2"
print(expanded_form(42))   # Should return "40 + 2"
print(expanded_form(70304))# Should return "70000 + 300 + 4"