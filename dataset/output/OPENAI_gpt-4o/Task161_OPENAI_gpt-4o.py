# Function to solve the knapsack problem
def knapsack(capacity, weights, values, n):
    K = [[0 for x in range(capacity + 1)] for x in range(n + 1)]
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif weights[i-1] <= w:
                K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
    return K[n][capacity]

weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
n = len(weights)
print(knapsack(capacity, weights, values, n))