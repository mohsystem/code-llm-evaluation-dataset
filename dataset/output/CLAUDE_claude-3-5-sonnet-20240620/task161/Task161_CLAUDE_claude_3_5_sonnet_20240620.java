
import java.util.Scanner;

public class Task161_CLAUDE_claude_3_5_sonnet_20240620 {
    static int knapsack(int capacity, int[] weights, int[] values, int n) {
        int[][] dp = new int[n + 1][capacity + 1];
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= capacity; w++) {
                if (weights[i-1] <= w) {
                    dp[i][w] = Math.max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        return dp[n][capacity];
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter knapsack capacity: ");
        int capacity = scanner.nextInt();
        
        System.out.print("Enter number of items: ");
        int n = scanner.nextInt();
        
        int[] weights = new int[n];
        int[] values = new int[n];
        
        System.out.print("Enter weights of items: ");
        for (int i = 0; i < n; i++) {
            weights[i] = scanner.nextInt();
        }
        
        System.out.print("Enter values of items: ");
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }
        
        System.out.println("Maximum value: " + knapsack(capacity, weights, values, n));
        
        scanner.close();
    }
}
