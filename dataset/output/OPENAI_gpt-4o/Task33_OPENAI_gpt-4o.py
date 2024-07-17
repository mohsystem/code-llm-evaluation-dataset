from heapq import heappop, heappush, heapify

def queue_time(customers, n):
    tills = [0] * n
    heapify(tills)
    for time in customers:
        current = heappop(tills)
        heappush(tills, current + time)
    return max(tills)

if __name__ == "__main__":
    print(queue_time([5, 3, 4], 1))  # should return 12
    print(queue_time([10, 2, 3, 3], 2))  # should return 10
    print(queue_time([2, 3, 10], 2))  # should return 12