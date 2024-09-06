class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [(nums[i], i) for i in range(n)]
        res = [0] * n

        def merge_sort(left, right):
            if left >= right:
                return
            mid = (left + right) // 2
            merge_sort(left, mid)
            merge_sort(mid + 1, right)
            merge(left, mid, right)

        def merge(left, mid, right):
            i = left
            j = mid + 1
            k = 0
            temp = [0] * (right - left + 1)
            smaller_count = 0
            while i <= mid and j <= right:
                if arr[i][0] <= arr[j][0]:
                    temp[k] = arr[i]
                    res[arr[i][1]] += smaller_count
                    i += 1
                    k += 1
                else:
                    temp[k] = arr[j]
                    smaller_count += 1
                    j += 1
                    k += 1
            while i <= mid:
                temp[k] = arr[i]
                res[arr[i][1]] += smaller_count
                i += 1
                k += 1
            while j <= right:
                temp[k] = arr[j]
                j += 1
                k += 1
            for i in range(left, right + 1):
                arr[i] = temp[i - left]

        merge_sort(0, n - 1)
        return res