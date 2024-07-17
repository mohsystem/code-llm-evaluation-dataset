import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");

        if (scanner.hasNextDouble()) {
            double num = scanner.nextDouble();
            System.out.println("The square of the number is: " + (num * num));
        } else {
            System.out.println("Invalid input. Please enter a number.");
        }

        scanner.close();
    }
}