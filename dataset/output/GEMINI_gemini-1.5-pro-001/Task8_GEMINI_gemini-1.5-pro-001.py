def find_missing_letter(array):
    for i in range(1, len(array)):
        if ord(array[i]) - ord(array[i - 1]) != 1:
            return chr(ord(array[i]) - 1)
    return ' '


arr1 = ['a', 'b', 'c', 'd', 'f']
arr2 = ['O', 'Q', 'R', 'S']

print(find_missing_letter(arr1))
print(find_missing_letter(arr2))