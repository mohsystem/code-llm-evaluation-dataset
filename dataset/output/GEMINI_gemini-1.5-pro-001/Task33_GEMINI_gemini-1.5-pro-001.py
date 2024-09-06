def queue_time(customers, n):
    tills = [0] * n
    for time in customers:
        tills[0] += time
        tills.sort()
    return max(tills)