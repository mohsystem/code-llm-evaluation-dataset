def expanded_form(num):
    num_str = str(num)
    expanded = []
    for i, digit in enumerate(num_str):
        if digit != '0':
            expanded.append(digit + '0' * (len(num_str) - i - 1))
    return ' + '.join(expanded)