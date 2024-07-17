from sortedcontainers import SortedList

def count_smaller(nums):
    result = []
    sorted_list = SortedList()
    for num in reversed(nums):
        index = sorted_list.bisect_left(num)
        result.append(index)
        sorted_list.add(num)
    return result[::-1]