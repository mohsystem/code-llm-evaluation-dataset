# Python
def expandedForm(num):
    digits = [10000, 1000, 100, 10, 1]
    result = []
    for digit in digits:
        if num >= digit:
            count = num // digit
            result.append(str(count * digit))
            num -= count * digit
    return ' + '.join(result)