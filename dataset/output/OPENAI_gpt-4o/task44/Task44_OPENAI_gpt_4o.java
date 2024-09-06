import java.util.Scanner;

public class Task44_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        while (!scanner.hasNextInt()) {
            System.out.println("Invalid input. Please enter a number.");
            scanner.next(); // Discard invalid input
        }
        int number = scanner.nextInt();
        System.out.println("You entered: " + number);

        int squared = number * number;
        System.out.println("Square of the number: " + squared);
    }
}