
def queue_time(customers, n):
    tills = [0] * n
    for customer in customers:
        tills[0] += customer
        tills.sort()
    return max(tills)
