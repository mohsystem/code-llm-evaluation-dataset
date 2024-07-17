def knapsack(W, wt, val, n):
    K = [[0 for w in range(W + 1)] for i in range(n + 1)]
    
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
 
    return K[n][W]

W = int(input("Enter the capacity of the knapsack: "))
n = int(input("Enter the number of items: "))
val = list(map(int, input("Enter the values of the items: ").split()))
wt = list(map(int, input("Enter the weights of the items: ").split()))

print("Maximum value that can be put into the knapsack: ", knapsack(W, wt, val, n))