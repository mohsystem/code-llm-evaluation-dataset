
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        def merge_sort(enum):
            if len(enum) <= 1:
                return enum
            mid = len(enum) // 2
            left = merge_sort(enum[:mid])
            right = merge_sort(enum[mid:])
            for i in range(len(enum) - 1, -1, -1):
                if not right or (left and left[-1][1] > right[-1][1]):
                    result[left[-1][0]] += len(right)
                    enum[i] = left.pop()
                else:
                    enum[i] = right.pop()
            return enum
        
        result = [0] * len(nums)
        merge_sort(list(enumerate(nums)))
        return result
