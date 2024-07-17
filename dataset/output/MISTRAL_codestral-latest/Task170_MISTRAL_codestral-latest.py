def count_range_sum(nums, lower, upper):
    prefix_sums = [0]
    for num in nums:
        prefix_sums.append(prefix_sums[-1] + num)

    def count_while_merge_sort(start, end):
        if end <= start:
            return 0
        mid = start + (end - start) // 2
        count = count_while_merge_sort(start, mid) + count_while_merge_sort(mid + 1, end)
        j = k = mid + 1
        for i in range(start, mid + 1):
            while j <= end and prefix_sums[j] - prefix_sums[i] < lower:
                j += 1
            while k <= end and prefix_sums[k] - prefix_sums[i] <= upper:
                k += 1
            count += k - j
        prefix_sums[start:end + 1] = sorted(prefix_sums[start:end + 1])
        return count

    return count_while_merge_sort(0, len(nums))