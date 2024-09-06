def reversePairs(nums):
    def mergeSort(nums):
        if len(nums) <= 1:
            return nums, 0
        mid = len(nums) // 2
        left, left_count = mergeSort(nums[:mid])
        right, right_count = mergeSort(nums[mid:])
        merged, merged_count = merge(left, right)
        return merged, left_count + right_count + merged_count

    def merge(left, right):
        merged = []
        left_index, right_index = 0, 0
        count = 0
        while left_index < len(left) and right_index < len(right):
            if left[left_index] <= 2 * right[right_index]:
                merged.append(left[left_index])
                left_index += 1
            else:
                merged.append(right[right_index])
                count += len(left) - left_index
                right_index += 1
        merged.extend(left[left_index:])
        merged.extend(right[right_index:])
        return merged, count

    return mergeSort(nums)[1]