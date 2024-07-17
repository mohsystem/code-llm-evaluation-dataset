def reversePairs(nums):
    def mergeSort(nums):
        if len(nums) <= 1:
            return nums, 0
        mid = len(nums) // 2
        left, leftCount = mergeSort(nums[:mid])
        right, rightCount = mergeSort(nums[mid:])
        merged, mergedCount = merge(left, right)
        return merged, leftCount + rightCount + mergedCount

    def merge(left, right):
        merged = []
        leftIndex, rightIndex, mergedCount = 0, 0, 0
        while leftIndex < len(left) and rightIndex < len(right):
            if left[leftIndex] <= 2 * right[rightIndex]:
                merged.append(left[leftIndex])
                leftIndex += 1
            else:
                merged.append(right[rightIndex])
                mergedCount += len(left) - leftIndex
                rightIndex += 1
        merged.extend(left[leftIndex:])
        merged.extend(right[rightIndex:])
        return merged, mergedCount

    return mergeSort(nums)[1]