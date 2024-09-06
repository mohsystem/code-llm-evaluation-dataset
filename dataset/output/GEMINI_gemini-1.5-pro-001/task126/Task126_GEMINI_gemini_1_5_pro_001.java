import java.util.Scanner;

public class Task126_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your destination (A, B, or C): ");
        String choice = scanner.nextLine().toUpperCase();

        if (choice.equals("A")) {
            System.out.println("Redirecting to page A...");
        } else if (choice.equals("B")) {
            System.out.println("Redirecting to page B...");
        } else if (choice.equals("C")) {
            System.out.println("Redirecting to page C...");
        } else {
            System.out.println("Invalid choice. Please enter A, B, or C.");
        }
    }
}