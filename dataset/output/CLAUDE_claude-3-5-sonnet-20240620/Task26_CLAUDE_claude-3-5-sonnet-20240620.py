
def find_odd(arr):
    result = 0
    for num in arr:
        result ^= num
    return result

# Test cases
print(find_odd([7]))
print(find_odd([0]))
print(find_odd([1,1,2]))
print(find_odd([0,1,0,1,0]))
print(find_odd([1,2,2,3,3,3,4,3,3,3,2,2,1]))
