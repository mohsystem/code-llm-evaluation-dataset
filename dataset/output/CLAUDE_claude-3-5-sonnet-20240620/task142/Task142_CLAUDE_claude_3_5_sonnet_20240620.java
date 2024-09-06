
import java.util.Scanner;

public class Task142_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int num1 = scanner.nextInt();
        System.out.print("Enter second number: ");
        int num2 = scanner.nextInt();
        int result = gcd(num1, num2);
        System.out.printf("The Task142_CLAUDE_claude_3_5_sonnet_20240620 of %d and %d is %d%n", num1, num2, result);
        scanner.close();
    }
}
