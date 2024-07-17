def knapsack(capacity, weights, values, n):
    if n == 0 or capacity == 0:
        return 0
    if weights[n-1] > capacity:
        return knapsack(capacity, weights, values, n-1)
    else:
        return max(values[n-1] + knapsack(capacity-weights[n-1], weights, values, n-1), knapsack(capacity, weights, values, n-1))

# Test the function
capacity = 50
values = [60, 100, 120]
weights = [10, 20, 30]
n = len(values)
print(knapsack(capacity, weights, values, n))