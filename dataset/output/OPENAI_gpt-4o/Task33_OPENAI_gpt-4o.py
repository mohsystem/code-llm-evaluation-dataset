def queue_time(customers, n):
    tills = [0] * n
    for time in customers:
        tills.sort()
        tills[0] += time
    return max(tills)

print(queue_time([5,3,4], 1))  # should return 12
print(queue_time([10,2,3,3], 2))  # should return 10
print(queue_time([2,3,10], 2))  # should return 12