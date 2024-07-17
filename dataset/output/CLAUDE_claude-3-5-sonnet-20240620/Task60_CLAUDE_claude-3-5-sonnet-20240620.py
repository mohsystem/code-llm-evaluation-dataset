
def expanded_form(num):
    num_str = str(num)
    result = []
    for i, digit in enumerate(num_str):
        if digit != \'0\':
            result.append(digit + \'0\' * (len(num_str) - i - 1))
    return \' + \'.join(result)

print(expanded_form(12))
print(expanded_form(42))
print(expanded_form(70304))
