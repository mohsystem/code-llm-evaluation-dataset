from collections import deque

def shortestSubarray(nums, k):
    n = len(nums)
    P = [0]
    for x in nums:
        P.append(P[-1] + x)

    ans = n + 1
    monoq = deque() 

    for y, Py in enumerate(P):
        while monoq and Py <= P[monoq[-1]]:
            monoq.pop()
        while monoq and Py >= P[monoq[0]] + k:
            ans = min(ans, y - monoq.popleft())

        monoq.append(y)

    return ans if ans < n + 1 else -1

if __name__ == "__main__":
    print(shortestSubarray([1], 1))  # Output: 1
    print(shortestSubarray([1, 2], 4))  # Output: -1
    print(shortestSubarray([2, -1, 2], 3))  # Output: 3