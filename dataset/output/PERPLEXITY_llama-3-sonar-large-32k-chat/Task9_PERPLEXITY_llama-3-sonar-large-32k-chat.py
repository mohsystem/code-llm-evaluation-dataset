def sum_type(arr):
    if len(arr) == 0: arr = [0]
    sum = 0
    for i in arr: sum += i
    return "even" if sum % 2 == 0 else "odd"

arr = [0, 1, 4]
print(sum_type(arr))