def countSmaller(nums):
    def sort(enum):
        if len(enum) <= 1:
            return enum
        mid = len(enum) // 2
        left = sort(enum[:mid])
        right = sort(enum[mid:])
        return merge(left, right)

    def merge(left, right):
        merge = []
        left_index = 0
        right_index = 0
        while left_index < len(left) and right_index < len(right):
            if left[left_index][1] <= right[right_index][1]:
                merge.append(left[left_index])
                left_index += 1
            else:
                merge.append(right[right_index])
                right_index += 1
        merge.extend(left[left_index:])
        merge.extend(right[right_index:])
        return merge

    enum = [(v, i) for i, v in enumerate(nums)]
    enum = sort(enum)
    counts = [0] * len(nums)
    for i in range(len(enum)):
        counts[enum[i][1]] = i
    return counts