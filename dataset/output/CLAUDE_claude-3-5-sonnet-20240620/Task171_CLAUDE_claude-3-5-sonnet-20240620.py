
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
            
            merge(arr, left, mid, right)
            return count
        
        def merge(arr, left, mid, right):
            temp = []
            i, j = left, mid + 1
            
            while i <= mid and j <= right:
                if arr[i] <= arr[j]:
                    temp.append(arr[i])
                    i += 1
                else:
                    temp.append(arr[j])
                    j += 1
            
            while i <= mid:
                temp.append(arr[i])
                i += 1
            
            while j <= right:
                temp.append(arr[j])
                j += 1
            
            for i in range(len(temp)):
                arr[left + i] = temp[i]
        
        return mergeSort(nums, 0, len(nums) - 1)

# Example usage
nums1 = [1,3,2,3,1]
nums2 = [2,4,3,5,1]
solution = Solution()
print(solution.reversePairs(nums1))  # Output: 2
print(solution.reversePairs(nums2))  # Output: 3
