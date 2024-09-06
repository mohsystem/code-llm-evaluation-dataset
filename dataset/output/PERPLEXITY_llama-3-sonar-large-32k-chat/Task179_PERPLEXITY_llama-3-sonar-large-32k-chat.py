from collections import deque

def maxSlidingWindow(nums, k):
    if not nums:
        return []
    if k == 0:
        return []
    
    dq = deque()
    output = []
    
    for i in range(len(nums)):
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        dq.append(i)
        
        if i >= k - 1:
            output.append(nums[dq[0]])
    
    return output