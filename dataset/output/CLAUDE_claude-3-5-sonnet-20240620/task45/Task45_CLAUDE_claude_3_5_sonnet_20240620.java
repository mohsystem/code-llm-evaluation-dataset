
import java.util.Scanner;

public class Task45_CLAUDE_claude_3_5_sonnet_20240620 {
    public static double divideNumbers(double a, double b) {
        return a / b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter first number: ");
            double num1 = Double.parseDouble(scanner.nextLine());

            System.out.print("Enter second number: ");
            double num2 = Double.parseDouble(scanner.nextLine());

            double result = divideNumbers(num1, num2);
            System.out.println("Result: " + result);
        } catch (NumberFormatException e) {
            System.out.println("Error: Please enter valid numbers.");
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        } finally {
            System.out.println("Program execution completed.");
            scanner.close();
        }
    }
}
