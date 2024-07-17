def longestRun(nums):
  if len(nums) <= 1:
    return len(nums)
  longest = 1
  current = 1
  for i in range(1, len(nums)):
    if nums[i] == nums[i-1] + 1 or nums[i] == nums[i-1] - 1:
      current += 1
    else:
      current = 1
    longest = max(longest, current)
  return longest