def reversePairs(nums):
    def merge_sort(nums, start, end):
        if end - start <= 1: 
            return 0
        
        mid = (start + end) // 2
        count = merge_sort(nums, start, mid) + merge_sort(nums, mid, end)
        j = mid
        for i in range(start, mid):
            while j < end and nums[i] > 2 * nums[j]:
                j += 1
            count += j - mid
        
        nums[start:end] = sorted(nums[start:end])
        return count
    
    return merge_sort(nums, 0, len(nums))

# Example usage
nums = [1, 3, 2, 3, 1]
print(reversePairs(nums))  # Output: 2

nums = [2, 4, 3, 5, 1]
print(reversePairs(nums))  # Output: 3