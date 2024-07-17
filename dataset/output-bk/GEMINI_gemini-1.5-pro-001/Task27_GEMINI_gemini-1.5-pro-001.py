def find_outlier(integers):
    even = 0
    odd = 0
    even_num = 0
    odd_num = 0
    for i in range(len(integers)):
        if integers[i] % 2 == 0:
            even += 1
            even_num = integers[i]
        else:
            odd += 1
            odd_num = integers[i]

    if even > 1:
        return odd_num
    else:
        return even_num