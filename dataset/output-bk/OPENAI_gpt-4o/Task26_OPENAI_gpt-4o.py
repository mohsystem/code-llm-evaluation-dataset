def find_odd(arr):
    res = 0
    for num in arr:
        res ^= num
    return res

if __name__ == "__main__":
    array = [1,2,2,3,3,3,4,3,3,3,2,2,1]
    result = find_odd(array)
    print(result)