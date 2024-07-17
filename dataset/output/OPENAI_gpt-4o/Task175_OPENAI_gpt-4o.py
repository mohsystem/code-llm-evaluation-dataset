class MountainArray:
    def __init__(self, arr):
        self.arr = arr

    def get(self, index):
        return self.arr[index]

    def length(self):
        return len(self.arr)

def find_in_mountain_array(target, mountain_arr):
    def peak_index_in_mountain_array():
        left, right = 0, mountain_arr.length() - 1
        while left < right:
            mid = (left + right) // 2
            if mountain_arr.get(mid) < mountain_arr.get(mid + 1):
                left = mid + 1
            else:
                right = mid
        return left

    def binary_search(left, right, target, asc=True):
        while left <= right:
            mid = (left + right) // 2
            val = mountain_arr.get(mid)
            if val == target:
                return mid
            if asc:
                if val < target:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if val > target:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1

    peak = peak_index_in_mountain_array()
    result = binary_search(0, peak, target, asc=True)
    if result != -1:
        return result
    return binary_search(peak + 1, mountain_arr.length() - 1, target, asc=False)

# Example usage:
m = MountainArray([1, 2, 3, 4, 5, 3, 1])
print(find_in_mountain_array(3, m))  # Output: 2

m = MountainArray([0, 1, 2, 4, 2, 1])
print(find_in_mountain_array(3, m))  # Output: -1