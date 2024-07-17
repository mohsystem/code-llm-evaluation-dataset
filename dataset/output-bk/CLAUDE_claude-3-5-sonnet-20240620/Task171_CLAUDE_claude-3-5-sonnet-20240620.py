
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def mergeSort(arr, left, right):
            if left >= right:
                return 0
            
            mid = (left + right) // 2
            count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right)
            
            j = mid + 1
            for i in range(left, mid + 1):
                while j <= right and arr[i] > 2 * arr[j]:
                    j += 1
                count += j - (mid + 1)
            
            arr[left:right+1] = sorted(arr[left:right+1])
            return count
        
        return mergeSort(nums, 0, len(nums) - 1)
