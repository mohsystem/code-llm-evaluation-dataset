def expanded_form(num):
    str = ""
    len_num = len(str(num))
    for i in range(0, len_num):
        digit = int(num / pow(10, len_num - i - 1)) % 10
        if digit != 0:
            str += f"{int(digit * pow(10, len_num - i - 1))}"
            if i != len_num - 1:
                str += " + "
    return str

print(expanded_form(12))
print(expanded_form(42))
print(expanded_form(70304))