
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        def mergeSort(arr, left, right):
            if left >= right:
                return 0
            
            mid = (left + right) // 2
            count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right)
            
            j = k = mid + 1
            for i in range(left, mid + 1):
                while j <= right and arr[j] - arr[i] < lower:
                    j += 1
                while k <= right and arr[k] - arr[i] <= upper:
                    k += 1
                count += k - j
            
            arr[left:right+1] = sorted(arr[left:right+1])
            return count
        
        prefixSum = [0]
        for num in nums:
            prefixSum.append(prefixSum[-1] + num)
        
        return mergeSort(prefixSum, 0, len(prefixSum) - 1)
