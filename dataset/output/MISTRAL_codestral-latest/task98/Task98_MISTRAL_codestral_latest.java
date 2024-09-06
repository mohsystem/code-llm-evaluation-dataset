// Java
import java.util.Scanner;

public class Task98_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        if (scanner.hasNextInt()) {
            int userInput = scanner.nextInt();
            System.out.println("You entered: " + userInput);
        } else {
            System.out.println("Invalid input. Please enter an integer.");
        }
        scanner.close();
    }
}