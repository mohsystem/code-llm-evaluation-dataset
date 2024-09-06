import heapq

def queueTime(customers, n):
    if not customers:
        return 0
    tills = [0] * n
    for time in customers:
        min_till = tills.index(min(tills))
        tills[min_till] += time
    return max(tills)