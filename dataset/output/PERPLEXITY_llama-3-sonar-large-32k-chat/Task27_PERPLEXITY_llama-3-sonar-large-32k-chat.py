def find_outlier(integers):
    even = [num for num in integers if num % 2 == 0]
    odd = [num for num in integers if num % 2 != 0]
    return even[0] if len(even) == 1 else odd[0]