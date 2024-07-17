def find_missing_letter(array):
    for i in range(len(array) - 1):
        if ord(array[i + 1]) - ord(array[i]) > 1:
            return chr(ord(array[i]) + 1)
    return ' '

arr = ['a','b','c','d','f']
print(find_missing_letter(arr))