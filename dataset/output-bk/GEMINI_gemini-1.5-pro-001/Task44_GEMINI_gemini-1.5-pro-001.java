import java.util.Scanner;

public class UserInputOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get an integer from the user
        int integerInput = getIntegerInput(scanner, "Enter an integer: ");

        // Get a double from the user
        double doubleInput = getDoubleInput(scanner, "Enter a double: ");

        // Perform some operations on the input
        int sum = integerInput + (int) doubleInput;
        double product = integerInput * doubleInput;

        System.out.println("Sum: " + sum);
        System.out.println("Product: " + product);
    }

    private static int getIntegerInput(Scanner scanner, String prompt) {
        int input;
        do {
            System.out.print(prompt);
            while (!scanner.hasNextInt()) {
                System.out.println("Invalid input. Please enter an integer.");
                System.out.print(prompt);
                scanner.next(); // Consume the non-integer input
            }
            input = scanner.nextInt();
        } while (input <= 0);
        return input;
    }

    private static double getDoubleInput(Scanner scanner, String prompt) {
        double input;
        do {
            System.out.print(prompt);
            while (!scanner.hasNextDouble()) {
                System.out.println("Invalid input. Please enter a double.");
                System.out.print(prompt);
                scanner.next(); // Consume the non-double input
            }
            input = scanner.nextDouble();
        } while (input <= 0);
        return input;
    }
}