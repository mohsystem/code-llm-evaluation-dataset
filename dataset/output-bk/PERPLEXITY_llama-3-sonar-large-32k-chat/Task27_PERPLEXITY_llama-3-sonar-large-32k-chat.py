def find_outlier(integers):
    even_count = 0
    odd_count = 0
    even_num = 0
    odd_num = 0
    
    for i in integers:
        if i % 2 == 0:
            even_count += 1
            even_num = i
        else:
            odd_count += 1
            odd_num = i
    
    return even_num if even_count == 1 else odd_num

integers = [2, 4, 0, 100, 4, 11, 2602, 36]
print(find_outlier(integers))