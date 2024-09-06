from typing import List

class MountainArray:
    def __init__(self, arr: List[int]):
        self.arr = arr
        self.calls = 0  # Keep track of the number of calls.
    
    def get(self, index: int) -> int:
        self.calls += 1
        if self.calls > 100:
            raise Exception("Too many calls")
        return self.arr[index]
    
    def length(self) -> int:
        return len(self.arr)
    
def findInMountainArray(target: int, mountain_arr: 'MountainArray') -> int:
    def findPeakIndex(arr: 'MountainArray') -> int:
        left, right = 0, arr.length() - 1
        while left < right:
            mid = (left + right) // 2
            if arr.get(mid) < arr.get(mid + 1):
                left = mid + 1
            else:
                right = mid
        return left

    def binarySearch(arr: 'MountainArray', target: int, left: int, right: int, ascending: bool) -> int:
        while left <= right:
            mid = (left + right) // 2
            value = arr.get(mid)
            if value == target:
                return mid
            if value < target:
                if ascending:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if ascending:
                    right = mid - 1
                else:
                    left = mid + 1
        return -1

    peak = findPeakIndex(mountain_arr)
    index = binarySearch(mountain_arr, target, 0, peak, True)
    if index != -1:
        return index
    return binarySearch(mountain_arr, target, peak + 1, mountain_arr.length() - 1, False)

# Example usage:
mountain_arr = MountainArray([1, 2, 3, 4, 5, 3, 1])
print(findInMountainArray(3, mountain_arr))  # Output: 2