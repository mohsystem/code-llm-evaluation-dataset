def expanded_form(num):
    str_num = str(num)
    result = ""
    for i in range(len(str_num)):
        if str_num[i] != '0':
            result += str_num[i]
            result += "0" * (len(str_num) - i - 1)
            if i < len(str_num) - 1:
                result += " + "
    return result