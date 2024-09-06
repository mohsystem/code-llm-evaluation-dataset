def knapsack(capacity, weights, values):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][capacity]

capacity = int(input("Enter the capacity of the knapsack: "))
n = int(input("Enter the number of items: "))
weights = []
values = []
for i in range(n):
    weight = int(input(f"Enter the weight of item {i + 1}: "))
    value = int(input(f"Enter the value of item {i + 1}: "))
    weights.append(weight)
    values.append(value)

max_value = knapsack(capacity, weights, values)
print("Maximum value that can be put into the knapsack:", max_value)