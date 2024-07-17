def dig_pow(n, p):
    sum_val = sum(int(digit) ** (p + idx) for idx, digit in enumerate(str(n)))
    return sum_val // n if sum_val % n == 0 else -1

if __name__ == "__main__":
    print(dig_pow(89, 1))       # Output: 1
    print(dig_pow(92, 1))       # Output: -1
    print(dig_pow(695, 2))      # Output: 2
    print(dig_pow(46288, 3))    # Output: 51