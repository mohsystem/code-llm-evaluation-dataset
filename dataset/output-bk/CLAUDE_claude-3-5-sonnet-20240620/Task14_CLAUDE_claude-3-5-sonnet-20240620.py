
def find_even_index(arr):
    left_sum = 0
    right_sum = sum(arr)
    
    for i, num in enumerate(arr):
        right_sum -= num
        
        if left_sum == right_sum:
            return i
        
        left_sum += num
    
    return -1

# Test cases
arr1 = [1,2,3,4,3,2,1]
arr2 = [1,100,50,-51,1,1]
arr3 = [20,10,-80,10,10,15,35]

print(find_even_index(arr1))
print(find_even_index(arr2))
print(find_even_index(arr3))
