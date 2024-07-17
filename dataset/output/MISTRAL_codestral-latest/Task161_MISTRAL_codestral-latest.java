public class Knapsack {
    static int knapsack(int capacity, int weights[], int values[], int n) {
        if (n == 0 || capacity == 0)
            return 0;
        if (weights[n-1] > capacity)
            return knapsack(capacity, weights, values, n-1);
        else
            return Math.max(values[n-1] + knapsack(capacity-weights[n-1], weights, values, n-1), knapsack(capacity, weights, values, n-1));
    }

    public static void main(String args[]) {
        int capacity = 50;
        int values[] = {60, 100, 120};
        int weights[] = {10, 20, 30};
        int n = values.length;
        System.out.println(knapsack(capacity, weights, values, n));
    }
}