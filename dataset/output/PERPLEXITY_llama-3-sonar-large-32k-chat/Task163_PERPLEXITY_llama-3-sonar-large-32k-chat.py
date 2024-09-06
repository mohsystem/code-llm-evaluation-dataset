def longestRun(nums):
    if not nums:
        return 0
    nums = sorted(set(nums))
    longest_run = 1
    current_run = 1
    for i in range(1, len(nums)):
        if nums[i] - nums[i-1] == 1:
            current_run += 1
        else:
            longest_run = max(longest_run, current_run)
            current_run = 1
    return max(longest_run, current_run)