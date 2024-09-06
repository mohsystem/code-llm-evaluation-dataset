def find_outlier(integers):
    parity = integers[0] % 2 + integers[1] % 2 + integers[2] % 2
    if parity < 2:
        for i in integers:
            if i % 2 != 0:
                return i
    else:
        for i in integers:
            if i % 2 == 0:
                return i