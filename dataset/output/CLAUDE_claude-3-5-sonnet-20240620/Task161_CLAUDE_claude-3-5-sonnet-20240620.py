
def knapsack(capacity, weights, values, n):
    K = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif weights[i-1] <= w:
                K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
    
    return K[n][capacity]

capacity = int(input("Enter knapsack capacity: "))
n = int(input("Enter number of items: "))
weights = list(map(int, input("Enter weights of items: ").split()))
values = list(map(int, input("Enter values of items: ").split()))

print("Maximum value in Knapsack =", knapsack(capacity, weights, values, n))
