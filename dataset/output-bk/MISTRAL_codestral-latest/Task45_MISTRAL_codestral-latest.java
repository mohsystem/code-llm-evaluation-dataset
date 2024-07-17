import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter a number: ");
            int num = scanner.nextInt();
            System.out.println("You entered: " + num);
            // Perform operations with num here
        } catch (InputMismatchException e) {
            System.out.println("Error: Invalid input. Please enter a number.");
        } finally {
            scanner.close();
        }
    }
}