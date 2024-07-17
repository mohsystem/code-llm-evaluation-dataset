
import java.util.Scanner;

public class KnapsackProblem {
    static int knapsack(int capacity, int[] weights, int[] values, int n) {
        int[][] K = new int[n + 1][capacity + 1];
        
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (weights[i-1] <= w)
                    K[i][w] = Math.max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
                else
                    K[i][w] = K[i-1][w];
            }
        }
        
        return K[n][capacity];
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
        
        System.out.println("Maximum value in Knapsack = " + knapsack(capacity, weights, values, n));
        
        scanner.close();
    }
}
