import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first number: ");
        double x = scanner.nextDouble();

        System.out.print("Enter second number: ");
        double y = scanner.nextDouble();

        System.out.print("Enter operator (+, -, *, /): ");
        char op = scanner.next().charAt(0);

        switch (op) {
            case '+':
                System.out.println("Result: " + (x + y));
                break;
            case '-':
                System.out.println("Result: " + (x - y));
                break;
            case '*':
                System.out.println("Result: " + (x * y));
                break;
            case '/':
                if (y != 0) {
                    System.out.println("Result: " + (x / y));
                } else {
                    System.out.println("Cannot divide by zero");
                }
                break;
            default:
                System.out.println("Invalid operator");
                break;
        }

        scanner.close();
    }
}