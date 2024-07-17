import java.util.Scanner;

public class Main {
    static int knapsack(int W, int wt[], int val[], int n) {
        int K[][] = new int[n + 1][W + 1];
        
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i-1] <= w)
                    K[i][w] = Math.max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                else
                    K[i][w] = K[i-1][w];
            }
        }
 
        return K[n][W];
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the capacity of the knapsack: ");
        int W = scanner.nextInt();
        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();
        int val[] = new int[n];
        int wt[] = new int[n];
        System.out.print("Enter the values of the items: ");
        for (int i = 0; i < n; i++) {
            val[i] = scanner.nextInt();
        }
        System.out.print("Enter the weights of the items: ");
        for (int i = 0; i < n; i++) {
            wt[i] = scanner.nextInt();
        }
        
        System.out.println("Maximum value that can be put into the knapsack: " + knapsack(W, wt, val, n));
    }
}