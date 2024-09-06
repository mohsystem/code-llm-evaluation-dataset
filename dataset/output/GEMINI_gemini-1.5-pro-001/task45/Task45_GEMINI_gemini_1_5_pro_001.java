import java.util.Scanner;

public class Task45_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit");

            try {
                System.out.print("Enter your choice (1-5): ");
                int choice = scanner.nextInt();

                if (choice == 5) {
                    break;
                }

                if (choice >= 1 && choice <= 4) {
                    System.out.print("Enter the first number: ");
                    int num1 = scanner.nextInt();
                    System.out.print("Enter the second number: ");
                    int num2 = scanner.nextInt();

                    double result = performOperation(choice, num1, num2);
                    System.out.println("Result: " + result);
                } else {
                    System.out.println("Invalid choice. Please enter a number between 1 and 5.");
                }
            } catch (java.util.InputMismatchException e) {
                System.out.println("Error: Invalid input. Please enter an integer.");
                scanner.nextLine(); // consume the invalid input
            } catch (ArithmeticException e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }

    public static double performOperation(int choice, int num1, int num2) {
        switch (choice) {
            case 1:
                return num1 + num2;
            case 2:
                return num1 - num2;
            case 3:
                return num1 * num2;
            case 4:
                if (num2 == 0) {
                    throw new ArithmeticException("Cannot divide by zero.");
                }
                return (double) num1 / num2;
            default:
                throw new IllegalArgumentException("Invalid choice.");
        }
    }
}