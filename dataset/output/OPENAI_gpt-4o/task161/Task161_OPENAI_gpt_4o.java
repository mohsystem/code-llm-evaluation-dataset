import java.util.*;

public class Task161_OPENAI_gpt_4o {
    static int knapsack(int capacity, int weights[], int values[], int n) {
        int K[][] = new int[n + 1][capacity + 1];
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (weights[i - 1] <= w)
                    K[i][w] = Math.max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
        return K[n][capacity];
    }

    public static void main(String args[]) {
        int values[] = new int[] { 60, 100, 120 };
        int weights[] = new int[] { 10, 20, 30 };
        int capacity = 50;
        int n = values.length;
        System.out.println(knapsack(capacity, weights, values, n));
    }
}