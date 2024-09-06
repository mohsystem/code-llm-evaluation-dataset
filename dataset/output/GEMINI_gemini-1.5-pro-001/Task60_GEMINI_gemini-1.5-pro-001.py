def expanded_form(num):
    num_str = str(num)
    length = len(num_str)
    result = []
    for i, digit in enumerate(num_str):
        if digit != '0':
            result.append(digit + '0' * (length - i - 1))
    return ' + '.join(result)