
import java.util.Scanner;

public class Task57_CLAUDE_claude_3_5_sonnet_20240620 {
    public static long factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        long result = factorial(num);
        System.out.println("The factorial of " + num + " is " + result);
        scanner.close();
    }
}
