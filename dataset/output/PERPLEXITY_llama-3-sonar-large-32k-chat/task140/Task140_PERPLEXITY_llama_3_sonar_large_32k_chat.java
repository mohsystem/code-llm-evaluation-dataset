import java.util.Scanner;

public class Task140_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter first number: ");
        double num1 = scanner.nextDouble();

        System.out.println("Enter operator (+, -, *, /): ");
        String operator = scanner.next();

        System.out.println("Enter second number: ");
        double num2 = scanner.nextDouble();

        if (operator.equals("+")) {
            System.out.println("Result: " + (num1 + num2));
        } else if (operator.equals("-")) {
            System.out.println("Result: " + (num1 - num2));
        } else if (operator.equals("*")) {
            System.out.println("Result: " + (num1 * num2));
        } else if (operator.equals("/")) {
            if (num2 != 0) {
                System.out.println("Result: " + (num1 / num2));
            } else {
                System.out.println("Error Division by zero is not allowed.");
            }
        } else {
            System.out.println("Invalid operator. Please enter either +, -, * or /.");
        }
    }
}