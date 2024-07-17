def queue_time(customers, n):
    tills = [0] * n
    for i in customers:
        tills[tills.index(min(tills))] += i
    return max(tills)