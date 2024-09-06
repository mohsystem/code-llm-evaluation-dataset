
def knapsack(capacity, weights, values, n):
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i-1] <= w:
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]
    
    return dp[n][capacity]

capacity = int(input("Enter knapsack capacity: "))
n = int(input("Enter number of items: "))
weights = list(map(int, input("Enter weights of items: ").split()))
values = list(map(int, input("Enter values of items: ").split()))

print("Maximum value:", knapsack(capacity, weights, values, n))
