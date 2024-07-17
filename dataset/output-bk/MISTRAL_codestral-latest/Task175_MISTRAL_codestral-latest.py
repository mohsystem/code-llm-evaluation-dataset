# Python
# The code below uses binary search to find the target in the mountain array.
# It first finds the peak of the mountain array, then performs binary search in the increasing and decreasing parts of the array.

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        def find_peak(mountain_arr):
            left, right = 0, mountain_arr.length() - 1
            while left < right:
                mid = (left + right) // 2
                if mountain_arr.get(mid) < mountain_arr.get(mid + 1):
                    left = mid + 1
                else:
                    right = mid
            return left

        def binary_search(mountain_arr, target, left, right, key=lambda x: x):
            target = key(target)
            while left <= right:
                mid = (left + right) // 2
                cur = key(mountain_arr.get(mid))
                if cur == target:
                    return mid
                elif cur < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1

        peak = find_peak(mountain_arr)
        res = binary_search(mountain_arr, target, 0, peak)
        if res != -1:
            return res
        return binary_search(mountain_arr, target, peak + 1, mountain_arr.length() - 1, key=lambda x: -x)