import java.util.InputMismatchException;
import java.util.Scanner;

public class InputHandler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter first number: ");
            int num1 = scanner.nextInt();

            System.out.print("Enter second number: ");
            int num2 = scanner.nextInt();

            int sum = num1 + num2;
            int difference = num1 - num2;
            int product = num1 * num2;

            System.out.println("Sum: " + sum);
            System.out.println("Difference: " + difference);
            System.out.println("Product: " + product);

            if (num2 == 0) {
                System.out.println("Cannot divide by zero.");
            } else {
                double quotient = (double) num1 / num2;
                System.out.println("Quotient: " + quotient);
            }

        } catch (InputMismatchException e) {
            System.out.println("Invalid input. Please enter numbers only.");
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}