def find_outlier(arr):
    odd_count, even_count = 0, 0
    odd_num, even_num = 0, 0

    for i in range(len(arr)):
        if arr[i] % 2 == 0:
            even_count += 1
            even_num = arr[i]
        else:
            odd_count += 1
            odd_num = arr[i]
        if odd_count and even_count:
            break

    return odd_num if odd_count == 1 else even_num


example1 = [2, 4, 0, 100, 4, 11, 2602, 36]
example2 = [160, 3, 1719, 19, 11, 13, -21]

print(find_outlier(example1))  # Should print 11
print(find_outlier(example2))  # Should print 160